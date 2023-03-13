// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "App.xaml.g.h"

namespace winrt::winrt_mvvm::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);
        virtual void OnNavigationFailed(winrt::Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::Navigation::NavigationFailedEventArgs const&);
        winrt::Microsoft::UI::Xaml::Window& MainAppWindow();
    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };
    };
}
