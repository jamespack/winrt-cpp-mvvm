// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "TestPage.xaml.h"
#if __has_include("TestPage.g.cpp")
#include "TestPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::winrt_mvvm::implementation
{
    TestPage::TestPage()
    {
        InitializeComponent();
    }

    int32_t TestPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void TestPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void TestPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
    }
}
