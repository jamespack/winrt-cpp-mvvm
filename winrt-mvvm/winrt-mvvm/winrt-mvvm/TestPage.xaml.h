// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "TestPage.g.h"

namespace winrt::winrt_mvvm::implementation
{
    struct TestPage : TestPageT<TestPage>
    {
        TestPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::winrt_mvvm::factory_implementation
{
    struct TestPage : TestPageT<TestPage, implementation::TestPage>
    {
    };
}
