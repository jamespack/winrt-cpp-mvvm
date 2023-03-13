// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Composition::SystemBackdrops;
using namespace Microsoft::UI::Composition;


// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::winrt_mvvm::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        auto nativeWindow = this->try_as<IWindowNative>();
        HWND window;
        nativeWindow.get()->get_WindowHandle(&window);
        auto windowId = winrt::Microsoft::UI::GetWindowIdFromWindow(window);
        _appWindow = winrt::Microsoft::UI::Windowing::AppWindow::GetFromWindowId(windowId);
        
        auto presenter = _appWindow.Presenter();
        auto overLapped = presenter.try_as<winrt::Microsoft::UI::Windowing::OverlappedPresenter>();
        auto a = SetWindowLongPtrW(window, GWL_EXSTYLE, WS_EX_APPWINDOW);
        overLapped.SetBorderAndTitleBar(true, true);
        
    }

    void MainWindow::SetTitleBar()
    {
        auto titleBar = _appWindow.TitleBar();
        titleBar.ButtonBackgroundColor(winrt::Microsoft::UI::Colors::Transparent());
        titleBar.BackgroundColor(winrt::Microsoft::UI::Colors::Transparent());
        titleBar.ExtendsContentIntoTitleBar(true);
        titleBar.ButtonForegroundColor(winrt::Microsoft::UI::Colors::White());
        titleBar.PreferredHeightOption(winrt::Microsoft::UI::Windowing::TitleBarHeightOption::Standard);
        titleBar.IconShowOptions(winrt::Microsoft::UI::Windowing::IconShowOptions::HideIconAndSystemMenu);
        winrt::Windows::Graphics::RectInt32 dragRectangle;
        dragRectangle.Height = 40;
        dragRectangle.Width = _width;
        dragRectangle.X = 0;
        dragRectangle.Y = 0;

        std::array<winrt::Windows::Graphics::RectInt32, 1> dragRectangles;
        dragRectangles[0] = dragRectangle;
        titleBar.SetDragRectangles(dragRectangles);

    }

    bool MainWindow::TrySetMicaBackdrop()
    {
        if (!MicaController::IsSupported())
        {
            return false;
        }

        DispatcherQueueOptions options;
        options.apartmentType = DQTAT_COM_NONE;
        options.threadType = DQTYPE_THREAD_CURRENT;
        options.dwSize = sizeof(options);

        winrt::check_hresult(CreateDispatcherQueueController(options, reinterpret_cast<ABI::Windows::System::IDispatcherQueueController**>(winrt::put_abi(m_dispatcherQueue))));

        if (m_dispatcherQueue)
        {

            SetupSystemBackdropConfiguration();

            m_micaController.SetSystemBackdropConfiguration(m_configuration);
            m_micaController.AddSystemBackdropTarget(this->try_as<ICompositionSupportsSystemBackdrop>());

            return true;
        }

        return false;
    }

    void MainWindow::OnActivated(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::WindowActivatedEventArgs const& args)
    {
        m_configuration.IsInputActive(WindowActivationState::Deactivated != args.WindowActivationState());
    }
    void MainWindow::OnClosed(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::WindowEventArgs const& args)
    {
        if (nullptr != m_micaController)
        {
            m_micaController.Close();
            m_micaController = nullptr;
        }

        if (nullptr != m_dispatcherQueue)
        {
            m_dispatcherQueue.ShutdownQueueAsync();
            m_dispatcherQueue = nullptr;
        }
    }

    void MainWindow::OnThemeChanged(winrt::Microsoft::UI::Xaml::FrameworkElement const& element, winrt::Windows::Foundation::IInspectable const& sender)
    {
        m_configuration.Theme(ConvertToSystemBackdropTheme(m_rootElement.ActualTheme()));

    }


    void MainWindow::SetupSystemBackdropConfiguration()
    {
        m_configuration = SystemBackdropConfiguration();

        // Activation state.
        m_activatedRevoker = this->Activated(winrt::auto_revoke, { this, &MainWindow::OnActivated });

        m_closedRevoker = this->Closed(winrt::auto_revoke, { this, &MainWindow::OnClosed });

        // Initial state.
        m_configuration.IsInputActive(true);

        // Application theme.
        m_rootElement = this->Content().try_as<FrameworkElement>();
        if (nullptr != m_rootElement)
        {
            m_themeChangedRevoker = m_rootElement.ActualThemeChanged(winrt::auto_revoke, { this, &MainWindow::OnThemeChanged });

            // Initial state.
            m_configuration.Theme(ConvertToSystemBackdropTheme(m_rootElement.ActualTheme()));
        }
    }

    SystemBackdropTheme MainWindow::ConvertToSystemBackdropTheme(ElementTheme const& theme)
    {
        switch (theme)
        {
        case ElementTheme::Dark:
            return SystemBackdropTheme::Dark;
        case ElementTheme::Light:
            return SystemBackdropTheme::Light;
        default:
            return SystemBackdropTheme::Default;
        }
    }

    void MainWindow::OnSizeChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::WindowSizeChangedEventArgs const& args)
    {
        auto xamlRoot = this->Content().XamlRoot();
        _width = args.Size().Width;
        _height = args.Size().Height;
    }

}


