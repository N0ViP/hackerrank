#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return (document[n-1][m-1][k-1]);
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return (document[m-1][k-1]);
}

char*** kth_paragraph(char**** document, int k) {
    return (document[k-1]);
}

char**** get_document(char* text) {
    char ****doc;
    unsigned short paragraphs_cnt = 0, sentences_cnt = 0, words_cnt = 0;
    char *save_paragraphs, *save_sentences, *save_words;
    unsigned short p_idx = 0, s_idx = 0, w_idx = 0;
    char *paragraph, *sentence, *word;
    
    for (int i = 0; text[i]; i++)
    {
        if (text[i] == '\n')
        {
            paragraphs_cnt++;
        }
    }
    paragraphs_cnt++;
    
    doc = malloc(sizeof(char ***) * (paragraphs_cnt + 1));
    if (!doc)
    {
        exit (1);
    }
    
    paragraph = strtok_r(text, "\n", &save_paragraphs);
    
    while (paragraph)
    {
        s_idx = 0;
        sentences_cnt = 0;
        for (int i = 0; paragraph[i]; i++)
        {
            if (paragraph[i] == '.')
            {
                sentences_cnt++;
            }
        }
        
        doc[p_idx] = malloc(sizeof(char **) * (sentences_cnt + 1));
        if (!doc[p_idx])
        {
            exit (1);
        }
        
        sentence = strtok_r(paragraph, ".", &save_sentences);
        while (sentence)
        {
            w_idx = 0;
            words_cnt = 0;
            for (int i = 0; sentence[i]; i++)
            {
                if (sentence[i] == ' ')
                {
                    words_cnt++;
                }
            }
            words_cnt++;
            
            doc[p_idx][s_idx] = malloc(sizeof(char *) * (words_cnt + 1));
            if (!doc[p_idx][s_idx])
            {
                exit (1);
            }
            word = strtok_r(sentence, " ", &save_words);
            while (word)
            {
                doc[p_idx][s_idx][w_idx++] = word;
                word = strtok_r(NULL, " ", &save_words);
            }
            doc[p_idx][s_idx][w_idx] = NULL;
            
            sentence = strtok_r(NULL, ".", &save_sentences);
            s_idx++;
        }
        doc[p_idx][s_idx] = NULL;
    
        paragraph = strtok_r(NULL, "\n", &save_paragraphs);
        p_idx++;
    }
    doc[p_idx] = NULL;
    
    return (doc);
}


char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}
