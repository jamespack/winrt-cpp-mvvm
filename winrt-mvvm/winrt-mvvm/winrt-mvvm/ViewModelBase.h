#pragma once
#include "ViewModelBase.g.h"


namespace winrt::winrt_mvvm::implementation
{
    struct ViewModelBase : ViewModelBaseT<ViewModelBase>
    {
        ViewModelBase();
        virtual void OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& args);
        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
        void OnPropertyChanged(hstring const& propertyName);
        winrt::Windows::Foundation::Collections::IObservableVector<hstring> Items() const;
        void Items(winrt::Windows::Foundation::Collections::IObservableVector<hstring> const& items);
        winrt::winrt_mvvm::RelayCommand DoSomethingCommand();
        void DoSomethingCommand(winrt::winrt_mvvm::RelayCommand const& value);
        void DoSomething(winrt::Windows::Foundation::IInspectable const& parameter);

        
    private:
        winrt::event<winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> _propertyChanged;
        winrt::Windows::Foundation::Collections::IObservableVector<hstring> _items;
        winrt::winrt_mvvm::RelayCommand _command;

    };
}
namespace winrt::winrt_mvvm::factory_implementation
{
    struct ViewModelBase : ViewModelBaseT<ViewModelBase, implementation::ViewModelBase>
    {
    };
}
