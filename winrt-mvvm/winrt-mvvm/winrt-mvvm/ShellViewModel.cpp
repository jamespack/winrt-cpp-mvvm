#include "pch.h"
#include "ShellViewModel.h"
#include "ShellViewModel.g.cpp"


namespace winrt::winrt_mvvm::implementation
{
    void ShellViewModel::OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& args)
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
        _headerText = value;
        ViewModelBase::OnPropertyChanged(L"HeaderText");
    }

    void ShellViewModel::OnPropertyChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventArgs const& args)
    {
        auto size = ViewModelBase::Items().Size();
        if (size > 0)
        {
            ViewModelBase::Items().RemoveAtEnd();
        }
        else {
            PropertyChanged(_propertyChanged);
        }
    }

    void ShellViewModel::Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        HeaderText(L"Button Clicked!");
    }



}
