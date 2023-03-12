#pragma once
#include "MenuEntry.g.h"


namespace winrt::winrt_mvvm::implementation
{
    struct MenuEntry : MenuEntryT<MenuEntry>
    {
        MenuEntry(winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem const& item, 
            winrt::Windows::UI::Xaml::Interop::TypeName  const& xamlPageType,
            winrt::hstring const& name,
            winrt::Microsoft::UI::Xaml::Controls::Symbol symbol);
        MenuEntry() = default;
        winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem Item();
        void Item(winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem const& value);
        winrt::Windows::UI::Xaml::Interop::TypeName PageTypeName();
        void PageTypeName(winrt::Windows::UI::Xaml::Interop::TypeName  const& value);
        hstring Name();
        void Name(hstring const& value);
        bool operator==(winrt_mvvm::MenuEntry const& right);
        void Symbol(winrt::Microsoft::UI::Xaml::Controls::Symbol const& symbol);
        winrt::Microsoft::UI::Xaml::Controls::Symbol Symbol() const;

    private:
        hstring _name;
        winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem _item;
        winrt::Windows::UI::Xaml::Interop::TypeName  _xamlType;
        winrt::Microsoft::UI::Xaml::Controls::Symbol _symbol;

    };
}

namespace winrt::winrt_mvvm::factory_implementation
{
    struct MenuEntry : MenuEntryT<MenuEntry, implementation::MenuEntry>
    {
    };
}
