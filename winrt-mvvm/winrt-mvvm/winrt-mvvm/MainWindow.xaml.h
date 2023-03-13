// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once
#include "MainWindow.g.h"

namespace winrt::winrt_mvvm::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();
        void OnActivated(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::WindowActivatedEventArgs const& args);
        void OnClosed(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::WindowEventArgs const& args);
        void OnThemeChanged(winrt::Microsoft::UI::Xaml::FrameworkElement const& element, winrt::Windows::Foundation::IInspectable const& sender);

        bool TrySetMicaBackdrop();
    private:
        winrt::Microsoft::UI::Dispatching::DispatcherQueueController m_dispatcherQueue{ nullptr };
        winrt::Microsoft::UI::Composition::SystemBackdrops::MicaController m_micaController;
        winrt::Microsoft::UI::Composition::SystemBackdrops::SystemBackdropConfiguration m_configuration;
        winrt::Microsoft::UI::Xaml::Window::Activated_revoker m_activatedRevoker;
        winrt::Microsoft::UI::Xaml::Window::Closed_revoker m_closedRevoker;
        winrt::Microsoft::UI::Xaml::FrameworkElement::ActualThemeChanged_revoker m_themeChangedRevoker;
        winrt::Microsoft::UI::Xaml::FrameworkElement m_rootElement{ nullptr };

        void SetupSystemBackdropConfiguration();
        winrt::Microsoft::UI::Composition::SystemBackdrops::SystemBackdropTheme MainWindow::ConvertToSystemBackdropTheme(winrt::Microsoft::UI::Xaml::ElementTheme const& theme);


    };
}

namespace winrt::winrt_mvvm::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
