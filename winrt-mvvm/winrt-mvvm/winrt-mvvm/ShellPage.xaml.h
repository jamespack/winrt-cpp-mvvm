// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "ShellPage.g.h"
#include "ShellViewModel.h"

namespace winrt::winrt_mvvm::implementation
{
    struct ShellPage : ShellPageT<ShellPage>
    {
        ShellPage();
        winrt_mvvm::ShellViewModel ViewModel() const;
        void ViewModel(winrt_mvvm::ShellViewModel const& value);
        void OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& args);
    private:
        winrt_mvvm::ShellViewModel _viewModel;
    public:
    };
}

namespace winrt::winrt_mvvm::factory_implementation
{
    struct ShellPage : ShellPageT<ShellPage, implementation::ShellPage>
    {
    };
}
