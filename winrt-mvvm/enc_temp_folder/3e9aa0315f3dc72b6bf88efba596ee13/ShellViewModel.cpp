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
    }

    void ShellViewModel::OnPropertyChanged([[maybe_unused]] winrt::Windows::Foundation::IInspectable const& sender, [[maybe_unused]] winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventArgs const& args)
    {

    }

    void ShellViewModel::Button_Click([[maybe_unused]] winrt::Windows::Foundation::IInspectable const& sender, [[maybe_unused]] winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        HeaderText(L"Button Clicked!");
        IsCommandEnabled(false);
    }


    ShellViewModel::ShellViewModel() : _shellCommand(nullptr), _navigationItems(winrt::single_threaded_observable_vector<winrt_mvvm::MenuEntry>())
    {
        auto home = winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem();
        auto test = winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem();


        _navigationItems.Append(winrt::make<winrt::winrt_mvvm::implementation::MenuEntry>(
                home,
                winrt::xaml_typename<winrt_mvvm::HomePage>(),
                L"Home"
        ));
        _navigationItems.Append(winrt::make<winrt::winrt_mvvm::implementation::MenuEntry>(
            test,
            winrt::xaml_typename<winrt_mvvm::HomePage>(),
            L"Test"
        ));


        winrt::delegate<IInspectable> command{get_strong(), &ShellViewModel::ShellCommandExecute};
        winrt::delegate<bool(IInspectable)> canExecute{ get_strong(), &ShellViewModel::ShellCommandCanExecute};
        
        ShellCommand(winrt::make<implementation::RelayCommand>(command, canExecute));

        _navigationFrame.Navigated({ this, &ShellViewModel::OnFrameNavigated });
        
    }


    winrt::Microsoft::UI::Xaml::Input::ICommand  ShellViewModel::ShellCommand()
    {
        return _shellCommand;
    }
    void ShellViewModel::ShellCommand(winrt::Microsoft::UI::Xaml::Input::ICommand  const& command)
    {
        _shellCommand = command;
    }
    void ShellViewModel::ShellCommandExecute([[maybe_unused]]winrt::Windows::Foundation::IInspectable const& parameter)
    {

    }

    bool ShellViewModel::ShellCommandCanExecute([[maybe_unused]]winrt::Windows::Foundation::IInspectable const& parameter)
    {
        return IsCommandEnabled();
    }

    void ShellViewModel::IsCommandEnabled(bool const& value)
    {
        _isCommandEnabled = value;
        _shellCommand.as<winrt_mvvm::RelayCommand>().OnCanExecuteChanged();
    }

    bool ShellViewModel::IsCommandEnabled() const
    {
        return _isCommandEnabled;
    }


    void ShellViewModel::OnShellLoaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {
        _navigationFrame.Navigate(winrt::xaml_typename<winrt_mvvm::HomePage>());
    }

    void ShellViewModel::OnFrameNavigated(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& args)
    {
        IsBackEnabled(_navigationFrame.BackStackDepth() > 0);
    }

    bool ShellViewModel::IsBackEnabled() const
    {
        return _isBackEnabled;
    }

    void ShellViewModel::IsBackEnabled(bool const& value)
    {
        _isBackEnabled = value;
        SetProperty(_isBackEnabled, value);
    }

    winrt::Microsoft::UI::Xaml::Controls::Frame ShellViewModel::NavigationFrame() const
    {
        return _navigationFrame;
    }
    void  ShellViewModel::NavigationFrame(winrt::Microsoft::UI::Xaml::Controls::Frame const& frame)
    {
        _navigationFrame = frame;
        SetProperty(_navigationFrame, frame);
    }


    void ShellViewModel::OnNavigtationItemInvoked(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewItemInvokedEventArgs const& args)
    {
        auto container = args.InvokedItem().try_as<winrt_mvvm::MenuEntry>();
        auto name = container.PageTypeName();
        auto a = args.InvokedItemContainer();
        winrt::Windows::UI::Xaml::Interop::TypeName typeName;
        typeName.Name = name.Name;
        typeName.Kind = winrt::Windows::UI::Xaml::Interop::TypeKind::Custom;
        NavigationFrame().Navigate(typeName);
    }
    void ShellViewModel::OnBackRequested(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewBackRequestedEventArgs const& args)
    {
        
        /*if (NavigationFrame.BackStack.LastOrDefault() is PageStackEntry entry)
        {
            NavigationView.SelectedItem = NavigationItems.First(item = > item.PageType == entry.SourcePageType).Item;

            NavigationFrame.GoBack();
        }*/
        if (_navigationFrame.CanGoBack())
        {
            auto size = _navigationFrame.BackStack().Size();
            auto lastItem = _navigationFrame.BackStack().GetAt(size -1);
            for (winrt_mvvm::MenuEntry& item : _navigationItems)
            {
                if ((L"winrt_mvvm." + item.Name() + L"Page") == lastItem.SourcePageType().Name)
                {
                     uint32_t index;

                     if (_navigationItems.IndexOf(item, index))
                     {
                        item.Item().IsSelected(true);
                        item.Item().Focus(winrt::Microsoft::UI::Xaml::FocusState::Pointer);
                        SelectedItem(item.Item());
                     }
                }
            }
            
            _navigationFrame.GoBack();
        }
    }

    winrt::Windows::Foundation::Collections::IObservableVector<winrt_mvvm::MenuEntry> ShellViewModel::NavigationItems() const
    {
        return _navigationItems;
    }
    void ShellViewModel::NavigationItems(winrt::Windows::Foundation::Collections::IObservableVector<winrt_mvvm::MenuEntry> const& items)
    {
        SetProperty(_navigationItems, items);
    }

    winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem ShellViewModel::SelectedItem() const
    {
        return _selectedItem;
    }
    void ShellViewModel::SelectedItem(winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem const& item)
    {
        SetProperty(_selectedItem, item);
    }

}
