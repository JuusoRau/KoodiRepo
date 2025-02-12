import tkinter as tk
from tkinter import ttk

def calculate_max():
    try:
        bar_weight = float(entry_bar_weight.get())
        reps = int(entry_reps.get())
        body_mass = float(entry_body_mass.get())
        
        if unit_var.get() == 'lbs':
            bar_weight /= 2.20462  # Convert lbs to kg
            body_mass /= 2.20462
        
        one_rep_max_kg = (bar_weight / reps) * body_mass
        one_rep_max_lbs = one_rep_max_kg * 2.20462  # Convert kg to lbs
        
        result_label.config(text=f"One-Rep Max: {one_rep_max_kg:.2f} kg / {one_rep_max_lbs:.2f} lbs")
    except ValueError:
        result_label.config(text="Please enter valid numbers!")

root = tk.Tk()
root.title("One-Rep Max Calculator")
root.geometry("400x300")

frame = ttk.Frame(root, padding=20)
frame.pack()

# Input Fields
unit_var = tk.StringVar(value='kg')
ttk.Label(frame, text="Bar Weight:").grid(row=0, column=0)
entry_bar_weight = ttk.Entry(frame)
entry_bar_weight.grid(row=0, column=1)

ttk.Label(frame, text="Repetitions:").grid(row=1, column=0)
entry_reps = ttk.Entry(frame)
entry_reps.grid(row=1, column=1)

ttk.Label(frame, text="Body Mass:").grid(row=2, column=0)
entry_body_mass = ttk.Entry(frame)
entry_body_mass.grid(row=2, column=1)

# Unit Selection
ttk.Label(frame, text="Unit:").grid(row=3, column=0)
unit_menu = ttk.OptionMenu(frame, unit_var, 'kg', 'lbs')
unit_menu.grid(row=3, column=1)

# Calculate Button
calculate_button = ttk.Button(frame, text="Calculate", command=calculate_max)
calculate_button.grid(row=4, columnspan=2, pady=10)

# Result Label
result_label = ttk.Label(frame, text="")
result_label.grid(row=5, columnspan=2)

root.mainloop()
