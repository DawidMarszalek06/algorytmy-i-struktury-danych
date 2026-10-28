import matplotlib.pyplot as plt

# Rozmiary wektorów
N = [10, 15, 20]

# Liczba porównań
merge2_porownania = [8, 6, 12]
merge3_porownania = [24, 44, 61]
insertion_porownania = [31, 64, 114]
pairwise_porownania = [20, 54, 81]
bubble_porownania = [81, 154, 247]

# Liczba przypisań
merge2_przypisania = [68, 118, 176]
merge3_przypisania = [44, 84, 120]
insertion_przypisania = [42, 80, 135]
pairwise_przypisania = [44, 78, 125]
bubble_przypisania = [48, 104, 194]

# --- 1. WYKRES PORÓWNAŃ ---
plt.figure(figsize=(8, 5))
plt.plot(N, merge2_porownania, marker='o', label='Sortowanie przez scalanie Mergesort2')
plt.plot(N, merge3_porownania, marker='s', label='Sortowanie przez scalanie Mergesort3')
plt.plot(N, insertion_porownania, marker='^', label='Sortowanie przez wstawianie Insertion')
plt.plot(N, pairwise_porownania, marker='d', label='Wstawianie parowe Insertion')
plt.plot(N, bubble_porownania, marker='x', label='Sortowanie bąbelkowe')

plt.title('Liczba porównań w zależności od rozmiaru wektora N')
plt.xlabel('Rozmiar wektora (N)')
plt.ylabel('Liczba porównań')
plt.xticks(N)
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()
plt.tight_layout()
plt.savefig('wykres_porownania.png', dpi=300)
plt.close()

# --- 2. WYKRES PRZYPISAŃ ---
plt.figure(figsize=(8, 5))
plt.plot(N, merge2_przypisania, marker='o', label='Sortowanie przez scalanie Mergesort2')
plt.plot(N, merge3_przypisania, marker='s', label='Sortowanie przez scalanie Mergesort3')
plt.plot(N, insertion_przypisania, marker='^', label='Sortowanie przez wstawianie Insertion')
plt.plot(N, pairwise_przypisania, marker='d', label='Wstawianie parowe Insertion')
plt.plot(N, bubble_przypisania, marker='x', label='Sortowanie bąbelkowe')

plt.title('Liczba przypisań w zależności od rozmiaru wektora N')
plt.xlabel('Rozmiar wektora (N)')
plt.ylabel('Liczba przypisań')
plt.xticks(N)
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()
plt.tight_layout()
plt.savefig('wykres_przypisania.png', dpi=300)
plt.close()

print("Wykresy zostały pomyślnie wygenerowane!")