#include "pch.h"
#include "ViewModelBase.h"
#include "ViewModelBase.g.cpp"
#include "RelayCommand.h"

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

	winrt::Windows::Foundation::Collections::IObservableVector<hstring> ViewModelBase::Items() const
	{
		return _items;
	}
	void ViewModelBase::Items(winrt::Windows::Foundation::Collections::IObservableVector<hstring> const& items)
	{
		_items = items;
		OnPropertyChanged(L"Items");
	}

	ViewModelBase::ViewModelBase() : _items(winrt::single_threaded_observable_vector<hstring>()), _command(nullptr)
	{
		_items.Append(L"One");
		_items.Append(L"Two");
		//_items.Append(L"Three");
		//_items.Append(L"Four");
		//_items.Append(L"Five");
		//_items.Append(L"Six");
		//_items.Append(L"Seven");
		//_items.Append(L"Eight");

		auto command = winrt::delegate<IInspectable>{get_weak(), &ViewModelBase::DoSomething};
		DoSomethingCommand(winrt::make<winrt_mvvm::implementation::RelayCommand>(command));
	}

	winrt::winrt_mvvm::RelayCommand ViewModelBase::DoSomethingCommand()
	{
		return _command;
	}

	void ViewModelBase::DoSomethingCommand(winrt::winrt_mvvm::RelayCommand const& value)
	{
		_command = value;
	}

	void ViewModelBase::DoSomething(winrt::Windows::Foundation::IInspectable const& parameter)
	{
		
	}

}
