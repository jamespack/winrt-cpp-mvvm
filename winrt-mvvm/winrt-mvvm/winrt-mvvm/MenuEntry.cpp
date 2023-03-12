#include "pch.h"
#include "MenuEntry.h"
#include "MenuEntry.g.cpp"


namespace winrt::winrt_mvvm::implementation
{
    winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem MenuEntry::Item()
    {
        return _item;
    }
    void MenuEntry::Item(winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem const& value)
    {
        _item = value;
    }
    winrt::Windows::UI::Xaml::Interop::TypeName  MenuEntry::PageTypeName()
    {
        return _xamlType;
    }
    void MenuEntry::PageTypeName(winrt::Windows::UI::Xaml::Interop::TypeName  const& value)
    {
        _xamlType = value;
    }
    hstring MenuEntry::Name()
    {
        return _name;
    }
    void MenuEntry::Name(hstring const& value)
    {
        _name = value;
    }

    MenuEntry::MenuEntry(winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem const& item, 
        winrt::Windows::UI::Xaml::Interop::TypeName  const& xamlPageType, hstring const& name) : _item(item), _xamlType(xamlPageType), _name(name)
    {

    }

}
