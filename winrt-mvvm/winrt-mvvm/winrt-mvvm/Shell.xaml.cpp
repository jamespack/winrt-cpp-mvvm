// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "Shell.xaml.h"
#if __has_include("Shell.g.cpp")
#include "Shell.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::winrt_mvvm::implementation
{
    Shell::Shell()
    {
        InitializeComponent();
    }


    winrt_mvvm::ShellViewModel Shell::ViewModel() const
    {
        return _viewModel;
    }
    void Shell::ViewModel(winrt_mvvm::ShellViewModel const& value)
    {
        _viewModel = value;
    }

}
