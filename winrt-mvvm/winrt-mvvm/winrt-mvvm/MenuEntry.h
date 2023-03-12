#pragma once
#include "MenuEntry.g.h"


namespace winrt::winrt_mvvm::implementation
{
    struct MenuEntry : MenuEntryT<MenuEntry>
    {
        MenuEntry(winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem const& item, winrt::Windows::UI::Xaml::Interop::TypeName  const& xamlPageType, winrt::hstring const& name);;

        winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem Item();
        void Item(winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem const& value);
        winrt::Windows::UI::Xaml::Interop::TypeName PageTypeName();
        void PageTypeName(winrt::Windows::UI::Xaml::Interop::TypeName  const& value);
        hstring Name();
        void Name(hstring const& value);

    private:
        hstring _name;
        winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem _item;
        winrt::Windows::UI::Xaml::Interop::TypeName  _xamlType;

    };
}
