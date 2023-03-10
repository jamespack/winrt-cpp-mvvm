#pragma once
#include "ShellViewModel.g.h"
#include "ViewModelBase.h"


namespace winrt::winrt_mvvm::implementation
{
    struct ShellViewModel : ShellViewModelT<ShellViewModel, winrt_mvvm::implementation::ViewModelBase>
    {
        ShellViewModel() = default;
        hstring HeaderText();
        void HeaderText(hstring const& value);
        void OnPropertyChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventArgs const& args);
        void OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& args);
        void Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);


    private:
        hstring _headerText;
        winrt::event_token _propertyChanged;
    };
}
namespace winrt::winrt_mvvm::factory_implementation
{
    struct ShellViewModel : ShellViewModelT<ShellViewModel, implementation::ShellViewModel>
    {
    };
}
