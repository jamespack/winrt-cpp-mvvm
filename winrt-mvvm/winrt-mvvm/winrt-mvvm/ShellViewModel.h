#pragma once
#include "ShellViewModel.g.h"
#include "ViewModelBase.h"
#include "RelayCommand.h"
#include "MenuEntry.h"

#include <winrt/Microsoft.UI.Xaml.Controls.h>


namespace winrt::winrt_mvvm::implementation
{
    struct ShellViewModel : ShellViewModelT<ShellViewModel, winrt_mvvm::implementation::ViewModelBase>
    {
        ShellViewModel();
        uint32_t Width();
        void Width(uint32_t const& width);

        //Header Text
        hstring HeaderText();
        void HeaderText(hstring const& value);
        
        //ClickHandler
        void Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        
        //PropertyChanged
        void OnPropertyChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventArgs const& args);
        
        //Navigation
        void OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& args);
        
        //Relay Command
        winrt::Microsoft::UI::Xaml::Input::ICommand ShellCommand();
        void ShellCommand(winrt::Microsoft::UI::Xaml::Input::ICommand const& command);
        
        //Relay Command Execute/CanExecute
        void ShellCommandExecute(winrt::Windows::Foundation::IInspectable const& parameter);
        bool ShellCommandCanExecute(winrt::Windows::Foundation::IInspectable const& parameter);
        
        //Relay Command Enabled
        bool IsCommandEnabled() const;
        void IsCommandEnabled(bool const& value);

        void OnShellLoaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& args);

        void OnFrameNavigated(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& args);
        bool IsBackEnabled() const;
        void IsBackEnabled(bool const& value);
        
        winrt::Microsoft::UI::Xaml::Controls::Frame NavigationFrame() const;
        void  NavigationFrame(winrt::Microsoft::UI::Xaml::Controls::Frame const& frame);


        void OnNavigtationItemInvoked(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewItemInvokedEventArgs const& args);
        void OnBackRequested(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewBackRequestedEventArgs const& args);

        winrt::Windows::Foundation::Collections::IObservableVector<winrt::winrt_mvvm::MenuEntry> NavigationItems() const;
        void NavigationItems(winrt::Windows::Foundation::Collections::IObservableVector<winrt::winrt_mvvm::MenuEntry> const& items);
    
        winrt_mvvm::MenuEntry SelectedItem() const;
        void SelectedItem(winrt_mvvm::MenuEntry const& item);

    private:
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::winrt_mvvm::MenuEntry> _navigationItems;
        hstring _headerText;
        winrt::event_token _propertyChanged;
        winrt::Microsoft::UI::Xaml::Input::ICommand _shellCommand;
        winrt::Microsoft::UI::Xaml::Controls::Frame _navigationFrame;
        bool _isCommandEnabled = true;
        bool _isBackEnabled = false;
        winrt_mvvm::MenuEntry _selectedItem;
        uint32_t _width;

    };
}
namespace winrt::winrt_mvvm::factory_implementation
{
    struct ShellViewModel : ShellViewModelT<ShellViewModel, implementation::ShellViewModel>
    {
    };
}
