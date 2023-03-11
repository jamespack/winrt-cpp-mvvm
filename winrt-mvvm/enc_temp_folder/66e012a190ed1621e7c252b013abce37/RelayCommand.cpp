#include "pch.h"
#include "RelayCommand.h"
#include "RelayCommand.g.cpp"


namespace winrt::winrt_mvvm::implementation
{
    winrt::event_token RelayCommand::CanExecuteChanged(winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler)
    {
        return _canExecuteChanged.add(handler);
    }
    void RelayCommand::CanExecuteChanged(winrt::event_token const& token) noexcept
    {
        _canExecuteChanged.remove(token);
    }
    bool RelayCommand::CanExecute(winrt::Windows::Foundation::IInspectable const& parameter)
    {
        if (_canExecute) {
            auto canExe = _canExecute(parameter);
            if (canExe != _currentCanExecuteValue)
            {
                _canExecuteChanged(*this, parameter);
                return canExe;
            }
        }
        else {
            return true;
        }
    }
    void RelayCommand::Execute(winrt::Windows::Foundation::IInspectable const& parameter)
    {
        _command(parameter);
    }

    RelayCommand::RelayCommand(winrt::delegate<IInspectable> command) : _command(command)
    {}
    RelayCommand::RelayCommand(winrt::delegate<IInspectable> command, winrt::delegate<bool(IInspectable)> canExecute) : _command(command), _canExecute(canExecute), _currentCanExecuteValue(true)
    {}
}
