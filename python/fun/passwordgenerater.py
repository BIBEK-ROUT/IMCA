import random
import string
import os

while True:
    print("\n1. Generate Password\n2. Add New\n3. Update\n4. Delete\n5. Exit")

    # --- Choice Input Handling ---
    user_input = input("Please enter your choice: ").strip()
    if not user_input.isdigit():
        print("Invalid input! Please enter a number.")
        continue
    choice = int(user_input)
    if choice not in [1, 2, 3, 4, 5]:
        print("Invalid choice! Please select between 1–5.")
        continue

    # --- Add New ---
    if choice == 2:
        user_text = input("Enter the new one: ").strip()
        if not user_text:
            print("Cannot add empty entry.")
            continue
        with open("password.txt", "a") as f:
            f.write(user_text + "\n")
        print("Added successfully!")

    # --- Generate Password ---
    elif choice == 1:
        if not os.path.exists("password.txt"):
            print("File not found! Add something first.")
            continue

        with open("password.txt", "r") as f:
            lines = f.readlines()

        if not lines:
            print("File empty! Please add something first.")
            continue

        for idx, line in enumerate(lines, 1):
            print(idx, ".", line.strip())

        user_choice = input("Choice to generate password: ").strip()
        if not user_choice.isdigit():
            print("Invalid input, please enter a number.")
            continue
        user_choice = int(user_choice)
        if user_choice < 1 or user_choice > len(lines):
            print("Invalid choice.")
            continue

        selected = lines[user_choice-1].strip()
        lis = list(string.ascii_letters + string.digits + string.punctuation)
        random.seed(selected)
        password = "".join(random.choice(lis) for _ in range(13))
        print("Generated password:", password)

    # --- Update ---
    elif choice == 3:
        if not os.path.exists("password.txt"):
            print("File not found!")
            continue
        with open("password.txt", "r") as f:
            lines = f.readlines()
        if not lines:
            print("File empty! Nothing to update.")
            continue

        for idx, line in enumerate(lines, 1):
            print(idx, ".", line.strip())

        update_idx = input("Which line to update? ").strip()
        if not update_idx.isdigit():
            print("Invalid input, enter a number.")
            continue
        update_idx = int(update_idx) - 1
        if 0 <= update_idx < len(lines):
            new_text = input("Enter new text: ").strip()
            if not new_text:
                print("Cannot update with empty text.")
                continue
            lines[update_idx] = new_text + "\n"
            with open("password.txt", "w") as f:
                f.writelines(lines)
            print("Updated successfully!")
        else:
            print("Invalid line number.")

    # --- Delete ---
    elif choice == 4:
        if not os.path.exists("password.txt"):
            print("File not found!")
            continue
        with open("password.txt", "r") as f:
            lines = f.readlines()
        if not lines:
            print("File empty! Nothing to delete.")
            continue

        for idx, line in enumerate(lines, 1):
            print(idx, ".", line.strip())

        delete_idx = input("Choice to delete: ").strip()
        if not delete_idx.isdigit():
            print("Invalid input, please enter a number.")
            continue
        delete_idx = int(delete_idx)
        if 1 <= delete_idx <= len(lines):
            removed = lines.pop(delete_idx-1)
            with open("password.txt", "w") as f:
                f.writelines(lines)
            print("Deleted:", removed.strip())
        else:
            print("Invalid line number.")

    # --- Exit ---
    elif choice == 5:
        print(" Thank you!")
        break
