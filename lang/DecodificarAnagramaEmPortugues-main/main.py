def create_array(word_size, anagram_word):
    # Criando a lista
    array_list = ['_' for _ in range(word_size)]
    letter_counts = {}

    # Contando as letras
    for letter in anagram_word:
        if letter not in letter_counts:
            letter_counts[letter] = 1
        else:
            letter_counts[letter] += 1

    return array_list, letter_counts

def anagram_decoder(array_list, letter_counts, word_size, word_list):
    possible_words = []

    for word in word_list:
        word_array = list(word)
        if len(word) == word_size:
            word_letter_counts = {}
            for letter in word:
                if letter not in word_letter_counts:
                    word_letter_counts[letter] = 1
                else:
                    word_letter_counts[letter] += 1

            if word_letter_counts == letter_counts:
                found = True
                for i in range(word_size):
                    if array_list[i] != '_' and array_list[i] != word_array[i]:
                        found = False
                        break

                if found:
                    possible_words.append(word)

    return possible_words

def get_word():
    print("Escreva um anagrama:")
    return input()

def main():
    anagram_word = get_word()
    array_list, letter_counts = create_array(len(anagram_word), anagram_word)

    with open("palavras.txt", "r", encoding="utf-8") as arquivo:
        word_list = arquivo.read().splitlines()

    possible_words = anagram_decoder(array_list, letter_counts, len(anagram_word), word_list)

    print(f"Número total de palavras: {len(possible_words)}")
    print(f"Algumas das palavras possíveis: {possible_words[:5]}")


if __name__ == '__main__':
    main()