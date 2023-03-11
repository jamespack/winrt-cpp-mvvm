#pragma once
#include "RelayCommand.g.h"


namespace winrt::winrt_mvvm::implementation
{
    struct RelayCommand : RelayCommandT<RelayCommand>
    {
        RelayCommand() = default;
        RelayCommand(winrt::delegate<IInspectable> execute);
        RelayCommand(winrt::delegate<IInspectable> execute, winrt::delegate<bool(IInspectable)> canExecute);


        winrt::event_token CanExecuteChanged(winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler);
        void CanExecuteChanged(winrt::event_token const& token) noexcept;
        bool CanExecute(winrt::Windows::Foundation::IInspectable const& parameter);
        void Execute(winrt::Windows::Foundation::IInspectable const& parameter);

        void OnCanExecuteChanged();

    private:
        winrt::event<winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable>> _canExecuteChanged;
        winrt::delegate<IInspectable> _command;
        winrt::delegate<bool(IInspectable)> _canExecute;
    };
}
