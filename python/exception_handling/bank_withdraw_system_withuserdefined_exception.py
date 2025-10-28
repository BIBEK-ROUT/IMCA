import time

# Custom Exception Classes
class BalanceExceptionError(Exception):
    def __init__(self):
        super().__init__("Insufficient Balance.")

class InvalidPinExceptionError(Exception):
    def __init__(self):
        super().__init__("Wrong PIN entered.")

class AttemptExceptionError(Exception):
    pass

# Global State
attempts = 1
saved_pin = 1234
balance = 10000

def withdraw():
    global attempts, balance
    try:
        pin = int(input("Enter the PIN: "))
        if pin == saved_pin:
            try:
                amt = float(input("Enter the amount: "))
                if balance - amt < 1000:
                    raise BalanceExceptionError()
                balance -= amt
                print("Withdrawal successful. Remaining Balance:", balance)
            except Exception as e:
                print("Error:", e)
        else:
            attempts += 1
            raise InvalidPinExceptionError()
    except InvalidPinExceptionError as e:
        print("Error:", e)
        if attempts > 3:
            try:
                raise AttemptExceptionError("You have entered the wrong PIN 3 times. Account is locked for 20 seconds.")
            except AttemptExceptionError as e:
                print("LOCKED:", e)
                print("Please wait 1 hour (simulated).")
                time.sleep(20)  # use 3600 for real 1-hour lock
                return
        withdraw()
    except Exception as e:
        print("Unknown Error:", e)
    else:
        ans = input("Do you want to continue? (y/n): ")
        if ans.lower() == 'y':
            withdraw()
        else:
            print("Thank you!")

withdraw()
