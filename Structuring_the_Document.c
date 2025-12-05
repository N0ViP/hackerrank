#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document get_document(char* text) {
    struct document doc;
    char *paragraph, *save_paragraphs;
    char *sentence, *save_sentences;
    char *word, *save_words;
    unsigned short p_idx = 0, s_idx = 0, w_idx = 0;

    doc.paragraph_count = 0;
        
    for (int i = 0; text[i]; i++)
    {
        if (text[i] == '\n')
            doc.paragraph_count++;
    }
    doc.paragraph_count++;
    
    doc.data = malloc(sizeof(struct paragraph) * (doc.paragraph_count + 1));
    if (!doc.data)
        exit(1);
    
    paragraph = strtok_r(text, "\n", &save_paragraphs);
    while (paragraph)
    {
        doc.data[p_idx].sentence_count = 0;
        s_idx = 0;
        for (int i = 0; paragraph[i]; i++)
        {
            if (paragraph[i] == '.')
                doc.data[p_idx].sentence_count++;
        }
        
        doc.data[p_idx].data = malloc(sizeof(struct sentence) * (doc.data[p_idx].sentence_count + 1));
        if (!doc.data[p_idx].data)
            exit(1);
        
        sentence = strtok_r(paragraph, ".", &save_sentences);
        while (sentence)
        {
            w_idx = 0;
            doc.data[p_idx].data[s_idx].word_count = 0;
            for (int i = 0; sentence[i]; i++)
            {
                if (sentence[i] == ' ')
                    doc.data[p_idx].data[s_idx].word_count++;
            }
            doc.data[p_idx].data[s_idx].word_count++;
            
            doc.data[p_idx].data[s_idx].data = malloc(sizeof(struct word) * (doc.data[p_idx].data[s_idx].word_count + 1));
            if (!doc.data[p_idx].data[s_idx].data)
                exit(1);
            
            word = strtok_r(sentence, " ", &save_words);
            while (word)
            {
                doc.data[p_idx].data[s_idx].data[w_idx++].data = word;
                word = strtok_r(NULL, " ", &save_words);
            }
            doc.data[p_idx].data[s_idx].data[w_idx].data = NULL;
            
            sentence = strtok_r(NULL, ".", &save_sentences);
            s_idx++;
        }
        doc.data[p_idx].data[s_idx].data = NULL;
        p_idx++;
        paragraph = strtok_r(NULL, "\n", &save_paragraphs);
    }
    doc.data[p_idx].data = NULL;
    return (doc);
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return (Doc.data[n-1].data[m-1].data[k-1]);
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return (Doc.data[m-1].data[k-1]);
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return (Doc.data[k-1]);
}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
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

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}
