#pragma once
#include <exception>
class InsufficientFundsException : public std::exception
{
public:
    InsufficientFundsException() {}
    ~InsufficientFundsException() {}
    const char* what() const noexcept
    {
        return "Insufficient Funds.";
    }
    
};

