#ifndef ENUM_HPP
#define ENUM_HPP

enum AtmState{
    IDLE,
    SELECT_OPERATION,
    INSERT_CARD,
    INSERT_PIN,
    INSERT_AMOUNT,
    DISPENSING
};

enum Operation{
    WITHDRAWAL,
    DEPOSIT,
    CHECK_BALANCE
};

#endif