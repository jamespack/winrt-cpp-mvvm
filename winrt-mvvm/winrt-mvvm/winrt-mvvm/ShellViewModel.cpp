#include "pch.h"
#include "ShellViewModel.h"
#include "ShellViewModel.g.cpp"


namespace winrt::winrt_mvvm::implementation
{
    void ShellViewModel::OnNavigatedTo([[maybe_unused]] winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& args)
    {
         _propertyChanged = PropertyChanged({ this, &ShellViewModel::OnPropertyChanged });
        _headerText = L"Welcome to Shell Page";
    }

    hstring ShellViewModel::HeaderText()
    {
        return _headerText;
    }

    void ShellViewModel::HeaderText(hstring const& value)
    {
        SetProperty<hstring>(_headerText, value);
        //ViewModelBase::OnPropertyChanged(L"HeaderText");
    }

    void ShellViewModel::OnPropertyChanged([[maybe_unused]] winrt::Windows::Foundation::IInspectable const& sender, [[maybe_unused]] winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventArgs const& args)
    {
        auto size = ViewModelBase::Items().Size();
        if (size > 0)
        {
            ViewModelBase::Items().RemoveAtEnd();
        }
        else {
            PropertyChanged(_propertyChanged);
            IsCommandEnabled(false);
        }
    }

    void ShellViewModel::Button_Click([[maybe_unused]] winrt::Windows::Foundation::IInspectable const& sender, [[maybe_unused]] winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        HeaderText(L"Button Clicked!");
    }


    ShellViewModel::ShellViewModel() : _shellCommand(nullptr)
    {
        winrt::delegate<IInspectable> command{get_strong(), &ShellViewModel::ShellCommand};
        winrt::delegate<bool(IInspectable)> canExecute{ get_strong(), &ShellViewModel::ShellCommandCanExecute};
        
        ShellViewModelCommand(winrt::make<implementation::RelayCommand>(command, canExecute));
        
    }


    winrt_mvvm::RelayCommand ShellViewModel::ShellViewModelCommand()
    {
        return _shellCommand;
    }
    void ShellViewModel::ShellViewModelCommand(winrt::winrt_mvvm::RelayCommand const& command)
    {
        _shellCommand = command;
    }
    void ShellViewModel::ShellCommand([[maybe_unused]]winrt::Windows::Foundation::IInspectable const& parameter)
    {

    }

    bool ShellViewModel::ShellCommandCanExecute([[maybe_unused]]winrt::Windows::Foundation::IInspectable const& parameter)
    {
        return IsCommandEnabled();
    }

    void ShellViewModel::IsCommandEnabled(bool const& value)
    {
        _isCommandEnabled = value;
        _shellCommand.OnCanExecuteChanged();
    }

    bool ShellViewModel::IsCommandEnabled() const
    {
        return _isCommandEnabled;
    }

}
