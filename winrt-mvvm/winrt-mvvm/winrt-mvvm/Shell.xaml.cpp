// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "Shell.xaml.h"
#if __has_include("Shell.g.cpp")
#include "Shell.g.cpp"
#endif
#include "App.xaml.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::winrt_mvvm::implementation
{
    Shell::Shell()
    {
        InitializeComponent();
        auto app = Application::Current().try_as<App>();
        app.get()->MainAppWindow().SizeChanged({this, &Shell::OnAppWindowSizeChanged});
    }


    winrt_mvvm::ShellViewModel Shell::ViewModel() const
    {
        return _viewModel;
    }
    void Shell::ViewModel(winrt_mvvm::ShellViewModel const& value)
    {
        _viewModel = value;
    }

    void Shell::OnAppWindowSizeChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::WindowSizeChangedEventArgs const& args)
    {
        auto size = args.Size();
        Width(size.Width);
    }

}
