#pragma once
#include "ShellViewModel.g.h"
#include "ViewModelBase.h"
#include "RelayCommand.h"

namespace winrt::winrt_mvvm::implementation
{
    struct ShellViewModel : ShellViewModelT<ShellViewModel, winrt_mvvm::implementation::ViewModelBase>
    {
        ShellViewModel();
        
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
        winrt_mvvm::RelayCommand ShellViewModelCommand();
        void ShellViewModelCommand(winrt::winrt_mvvm::RelayCommand const& command);
        
        //Relay Command Execute/CanExecute
        void ShellCommand(winrt::Windows::Foundation::IInspectable const& parameter);
        bool ShellCommandCanExecute(winrt::Windows::Foundation::IInspectable const& parameter);
        
        //Relay Command Enabled
        bool IsCommandEnabled() const;
        void IsCommandEnabled(bool const& value);
        
    private:
        hstring _headerText;
        winrt::event_token _propertyChanged;
        winrt_mvvm::RelayCommand _shellCommand;
        bool _isCommandEnabled = true;
    };
}
namespace winrt::winrt_mvvm::factory_implementation
{
    struct ShellViewModel : ShellViewModelT<ShellViewModel, implementation::ShellViewModel>
    {
    };
}
