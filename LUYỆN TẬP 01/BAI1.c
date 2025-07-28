// KHAI BÁO
// CẤU TRÚC 1 TIẾN TRÌNH, CẤU TRÚC STACK UNDO, STACK REDO, MẢNG CHỨA TEXT, LENGHT=0;

#include<stdio.h>
#define MAX 100

// KHAI BAO MANG STRING
char text[MAX];
int len=0;

// KHAI BAO CAU TRUC 1 TIEN TRÌNH, THAO TÁC
typedef struct Operation {
    char action;
    char value;
}Operation;

// KHAI BAO CAU TRUC STACK

typedef struct Stack {
    Operation data[MAX];
    int top;
}Stack;
// KHOI TẠO STACK UNDO VÀ REDO
Stack stackUndo;
Stack stackRedo;
// CÁC THAO TÁC LÀM VIỆC VỚI NGĂN XẾP
//1. KHỞI TẠO
void initStack() {
    stackUndo.top = -1;
    stackRedo.top = -1;
}
//2. THÊM
void push(Stack *s, Operation operation) {
    // KIỂM TRA XEM STACK ĐÃ ĐẦY HAY CHƯA
    if (s->top == MAX - 1) {
        printf("Stack da day\n");
        return;
    }
    s->top++;
    s->data[s->top]=operation;
}
//3. XÓA
Operation pop(Stack *s) {
    if (s->top == -1) {
        Operation temp={'\0','\0'};
        printf("Stack rong\n");
        return temp;
    }
    // CÓ PHẦN TỬ ĐỂ XÓA
    // TRẢ VỀ PHẦN TỬ XÓA, VÀ GIẢM TOP ĐI 1
    return s->data[s->top--];

}
//4. KIỂM TRA ĐẦY HAY CHƯA
//5. KIỂM TRA RỖNG HAY KHÔNG?
// TẠO HÀM THÊM KÝ TỰ
void insert(Stack *s) {
    // KIỂM TRA XEM MẢNG ĐÃ ĐẦY HAY CHƯA
    if (len>=MAX-1) {
        printf("khong the nhap them ky tu\n");
        return;
    }
    char c;
    printf("moi nhap ky tu : ");
    getchar();
    scanf("%c",&c);
    text[len]=c;
    len++;
    // push vào ngăn xếp undo
    Operation x={'I',c};
    push(&stackUndo,x);
    // KHI INSERT PHẢI ĐƯA STACKREDO VỀ RỖNG
    stackRedo.top=-1;

}
// TẠO HÀM REDO
int undo() {
    if (len==0) {
        return 0;
    }
    len--;
    Operation x= pop(&stackUndo);
    push(&stackRedo,x);
}
void display() {
    // printf("%d",len);
    // kiểm tra trước khi hiển thị
    if (len==0) {
        return;
    }
    for (int i=0;i<len;i++) {
        printf("%c",text[i]);
    }
    printf("\n");
}
int main() {
    initStack();
    int choice;
    do {
        printf("1. INSERT\n");
        printf("2. UNDO \n");
        printf("3. REDO\n");
        printf("4. PRINT\n");
        printf("5. EXIT\n");
        printf("NHAP LUA CHON: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                // GOI HAM INSERT
                insert(&stackUndo);
                break;
            }
            case 2: {
                // UNDO
                undo();

                break;
            }
            case 3: {
                break;
            }
            case 4: {
                display();
                break;
            }
        }
    } while (choice != 5);
}
