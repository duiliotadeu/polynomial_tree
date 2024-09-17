import os
import ctypes
import tkinter as tk
from tkinter import filedialog, messagebox
from _ctypes import LoadLibrary

def load_dll(path: str) -> ctypes.CDLL:
    if path == "" or path is None:
        raise TypeError("Por favor, forneça um caminho válido.")
    handle = LoadLibrary(path)
    return ctypes.CDLL(name=path, handle=handle) if handle != 0 else handle

if os.name != "nt":
    raise Exception("Sistema Operacional inválido, este código funciona apenas no Windows.")

dll_path = r"./prografo.dll"

biblioteca_c = load_dll(dll_path)

biblioteca_c.run_prografo.restype = ctypes.c_int
biblioteca_c.run_prografo.argtypes = [ctypes.c_char_p, ctypes.c_char_p]

selected_file_path = ""
selected_execution_type = "-a"

def call_run_prografo(execution_type, file_path):
    execution_type_bytes = execution_type.encode('utf-8')
    file_path_bytes = file_path.encode('utf-8')
    
    result = biblioteca_c.run_prografo(execution_type_bytes, file_path_bytes)
    
    return result

def update_status(label, text_color, bg_color, status_label, status_panel):
    status_label.config(text=label, fg=text_color)
    status_panel.config(bg=bg_color)

def on_start_button_clicked(status_label, status_panel):
    global selected_file_path, selected_execution_type
    if not selected_file_path:
        update_status("ERRO: selecione um arquivo", "white", "red", status_label, status_panel)
    else:
        update_status("EM PROGRESSO", "white", "blue", status_label, status_panel)
        
        result = call_run_prografo(selected_execution_type, selected_file_path)

        if result == 0:
            update_status("CONCLUIDO", "white", "green", status_label, status_panel)
        else:
            update_status("ERRO: algo deu errado", "white", "red", status_label, status_panel)

def on_file_input_button_clicked(file_button):
    global selected_file_path
    file_path = filedialog.askopenfilename(title="Selecionar arquivo", filetypes=[("Todos os arquivos", "*.*")])
    if file_path:
        selected_file_path = file_path
        file_button.config(text=selected_file_path.split("/")[-1])

def on_execution_type_selected(radio_value):
    global selected_execution_type
    selected_execution_type = radio_value

def on_about():
    messagebox.showinfo(
        "Sobre o Prografo", 
        "O Prografo é uma ferramenta para encontrar conjuntos independentes máximos em um grafo."
    )

def create_interface():
    root = tk.Tk()
    root.title("Prografo - Software")
    root.geometry("440x530")

    title_label = tk.Label(root, text="Prografo", font=("Arial", 16, "bold"))
    title_label.pack(pady=10, anchor="w")

    file_select_label = tk.Label(root, text="Selecione o grafo no formato dimacs (.col):", font=("Arial", 10))
    file_select_label.pack(pady=5, anchor="w")

    file_button = tk.Button(root, text="Selecionar arquivo...", command=lambda: on_file_input_button_clicked(file_button))
    file_button.pack(pady=5, fill="x")

    execution_types = {
        "-a": "Encontrar um máximo (paralelizado)",
        "-b": "Encontrar um máximo (linear)",
        "-c": "Encontrar todos os máximos",
        "-d": "Encontrar todos os maximais"
    }
    
    radio_value = tk.StringVar(value="-a")
    execution_label = tk.Label(root, text="Selecione o tipo de execução:", font=("Arial", 10))
    execution_label.pack(pady=5, anchor="w")

    for key, description in execution_types.items():
        radio_button = tk.Radiobutton(root, text=description, variable=radio_value, value=key, command=lambda: on_execution_type_selected(radio_value.get()))
        radio_button.pack(anchor="w")

    status_title_label = tk.Label(root, text="Status", font=("Arial", 14, "bold"))
    status_title_label.pack(pady=10, anchor="w")

    status_panel = tk.Frame(root, bg="white", height=40, width=400)
    status_panel.pack(pady=5, fill="x", padx=5)
    
    status_label = tk.Label(status_panel, text="NÃO INICIADO", font=("Arial", 10), bg="white")
    status_label.pack(pady=10)

    start_button = tk.Button(root, text="Iniciar", command=lambda: on_start_button_clicked(status_label, status_panel))
    start_button.pack(pady=10, anchor="e", padx=10)

    menubar = tk.Menu(root)
    helpmenu = tk.Menu(menubar, tearoff=0)
    helpmenu.add_command(label="Sobre", command=on_about)
    menubar.add_cascade(label="Ajuda", menu=helpmenu)
    root.config(menu=menubar)

    root.mainloop()

if __name__ == "__main__":
    create_interface()
