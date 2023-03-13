// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "winrt/Microsoft.UI.Xaml.h"
#include "winrt/Microsoft.UI.Xaml.Markup.h"
#include "winrt/Microsoft.UI.Xaml.Controls.Primitives.h"
#include "Shell.g.h"
#include "ShellViewModel.h"

namespace winrt::winrt_mvvm::implementation
{
    struct Shell : ShellT<Shell>
    {
        Shell();
        winrt_mvvm::ShellViewModel ViewModel() const;
        void ViewModel(winrt_mvvm::ShellViewModel const& value);
        void OnAppWindowSizeChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::WindowSizeChangedEventArgs const& args);
    private:
        winrt_mvvm::ShellViewModel _viewModel;
    };
}

namespace winrt::winrt_mvvm::factory_implementation
{
    struct Shell : ShellT<Shell, implementation::Shell>
    {
    };
}
