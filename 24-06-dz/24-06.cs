using System;

namespace CreditCardApp
{
    public class CreditCard
    {
        public delegate void CreditCardHandler(CreditCard sender, double amount, string transactionType);
        public delegate void PinChangeHandler(CreditCard sender, int newPin);

        public event CreditCardHandler OnTransaction;
        public event PinChangeHandler OnPinChanged;

        public string CardNumber { get; private set; }
        public string Name { get; private set; }
        public string Date { get; private set; }
        private int pin;
        public double CreditLimit { get; private set; }
        public double Balance { get; private set; }

        public CreditCard(string cardNumber, string name, string date, int pin, double creditLimit)
        {
            CardNumber = cardNumber;
            Name = name;
            Date = date;
            this.pin = pin;
            CreditLimit = creditLimit;
            Balance = 0;
        }

        public void ReplenishBalance(double amount)
        {
            if (amount <= 0)
            {
                throw new ArgumentException("Amount must be positive");
            }
            Balance += amount;
            OnTransaction?.Invoke(this, amount, "Replenished");
        }

        public void SpendMoney(double amount)
        {
            if (amount <= 0)
            {
                throw new ArgumentException("Amount must be positive");
            }
            if (Balance + CreditLimit < amount)
            {
                throw new InvalidOperationException("Insufficient funds");
            }
            Balance -= amount;
            OnTransaction?.Invoke(this, amount, "Spent");
        }

        public void ChangePin(int oldPin, int newPin)
        {
            if (pin != oldPin)
            {
                Console.WriteLine("Incorrect PIN. Please try later.");
                return;
            }
            pin = newPin;
            OnPinChanged?.Invoke(this, newPin);
            Console.WriteLine("PIN changed successfully.");
        }
    }

    internal class Program
    {
        public static void TransactionHandler(CreditCard sender, double amount, string transactionType)
        {
            Console.WriteLine($"Transaction type: {transactionType}");
            Console.WriteLine($"Amount: {amount}$");
            Console.WriteLine($"New balance: {sender.Balance}$");
        }

        public static void PinChangedHandler(CreditCard sender, int newPin)
        {
            Console.WriteLine($"PIN changed to: {newPin}");
        }

        static void Main(string[] args)
        {
            CreditCard card = new CreditCard("1023-3243-5454-7133", "While Smile", "2024, 06, 24", 1234, 1000);

            card.OnTransaction += TransactionHandler;
            card.OnPinChanged += PinChangedHandler;

            while (true)
            {
                Console.WriteLine("\nChoose an action:");
                Console.WriteLine("1: + money");
                Console.WriteLine("2: - money");
                Console.WriteLine("3: Change PIN");
                Console.WriteLine("4: Unsubscribe Transaction Handler");
                Console.WriteLine("5: Subscribe Transaction Handler");
                Console.WriteLine("6: Unsubscribe PIN Change Handler");
                Console.WriteLine("7: Exit");

                string choice = Console.ReadLine();

                switch (choice)
                {
                    case "1":
                        Console.Write("Enter amount to replenish: ");
                        double replenishAmount = Convert.ToDouble(Console.ReadLine());
                        card.ReplenishBalance(replenishAmount);
                        break;
                    case "2":
                        Console.Write("Enter amount to spend: ");
                        double spendAmount = Convert.ToDouble(Console.ReadLine());
                        card.SpendMoney(spendAmount);
                        break;
                    case "3":
                        Console.Write("Enter old PIN: ");
                        int oldPin = Convert.ToInt32(Console.ReadLine());
                        Console.Write("Enter new PIN: ");
                        int newPin = Convert.ToInt32(Console.ReadLine());
                        card.ChangePin(oldPin, newPin);
                        break;
                    case "4":
                        card.OnTransaction -= TransactionHandler;
                        Console.WriteLine("Transaction handler unsubscribed.");
                        break;
                    case "5":
                        card.OnTransaction += TransactionHandler;
                        Console.WriteLine("Transaction handler subscribed.");
                        break;
                    case "6":
                        card.OnPinChanged -= PinChangedHandler;
                        Console.WriteLine("PIN change handler unsubscribed.");
                        break;
                    case "7":
                        return;
                    default:
                        Console.WriteLine("Invalid choice. Try again.");
                        break;
                }
            }
        }
    }
}
