#include "pch.h"
#include "ViewModelBase.h"
#include "ViewModelBase.g.cpp"


namespace winrt::winrt_mvvm::implementation
{
	winrt::event_token ViewModelBase::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
	{
		return _propertyChanged.add(handler);
	}
	void ViewModelBase::PropertyChanged(winrt::event_token const& token) noexcept
	{
		_propertyChanged.remove(token);
	}

	void ViewModelBase::OnPropertyChanged(hstring const& propertyName)
	{

		_propertyChanged(*this, winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ propertyName });

	}

	void ViewModelBase::OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& args)
	{

	}

}
