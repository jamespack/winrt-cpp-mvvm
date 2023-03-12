#pragma once
#include "ViewModelBase.g.h"


namespace winrt::winrt_mvvm::implementation
{
    struct ViewModelBase : ViewModelBaseT<ViewModelBase>
    {
        ViewModelBase();
        
        //Navigation
        virtual void OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& args);
        
        //PropertyChanged
        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
        void OnPropertyChanged(hstring const& propertyName);

        

    protected:
        template<typename T> bool
        SetProperty(T& field, T newValue, const char* memberName = __builtin_FUNCTION())
        {
            
            field = newValue;
            
            OnPropertyChanged(winrt::to_hstring(memberName));
            return true;
        }

        
    private:
        winrt::event<winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> _propertyChanged;

    };
}
namespace winrt::winrt_mvvm::factory_implementation
{
    struct ViewModelBase : ViewModelBaseT<ViewModelBase, implementation::ViewModelBase>
    {
    };
}
