// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "ShellPage.xaml.h"
#if __has_include("ShellPage.g.cpp")
#include "ShellPage.g.cpp"
#endif

#include "ShellViewModel.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::winrt_mvvm::implementation
{
    ShellPage::ShellPage()
    {
        InitializeComponent();
    }

    winrt_mvvm::ShellViewModel ShellPage::ViewModel() const
    {
        return _viewModel;
    }

    void ShellPage::ViewModel(winrt_mvvm::ShellViewModel const& value)
    {
        _viewModel = value;
    }

    void ShellPage::OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& args)
    {
        
        _viewModel = winrt_mvvm::ShellViewModel();
        _viewModel.OnNavigatedTo(args);
    }

}
