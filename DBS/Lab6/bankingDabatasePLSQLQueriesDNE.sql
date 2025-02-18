--1
create or replace function withdraw_money (
    p_account_id in number,
    p_amount in number
) return varchar2 is
    v_balance number;
    v_new_balance number;
begin
    select balance into v_balance
    from bank_accounts
    where account_id = p_account_id
    for update;
    if v_balance < p_amount then
        raise_application_error(-20001, 'insufficient balance in the account.');
    else
        v_new_balance := v_balance - p_amount;
        update bank_accounts
        set balance = v_new_balance
        where account_id = p_account_id;
        commit;
        return 'withdrawal successful. new balance is ' || v_new_balance;
    end if;
exception
    when no_data_found then
        raise_application_error(-20002, 'account not found.');
    when others then
        rollback;
        raise;
end;
/