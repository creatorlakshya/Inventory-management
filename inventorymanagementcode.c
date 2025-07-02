#include <stdio.h>
#include <string.h>

struct item {
    int itno, rs, qty;
    char na[20];
};

int main() {
    struct item it[100], pur[100], sal[100];
    int itc = 0, puc = 0, sac = 0;
    int ch = 1, xit, xqty;
    
    while (ch != 0) {
        printf("\n======= MENU =======\n");
        printf("1. Add Item\n");
        printf("2. Purchase Item\n");
        printf("3. Sell Item\n");
        printf("4. Show Purchase Details\n");
        printf("5. Show Sales Details\n");
        printf("6. Show Stock\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\n-- Add Items --\n");
                while (1) {
                    printf("Enter item number (0 to stop): ");
                    scanf("%d", &xit);
                    if (xit == 0) break;

                    printf("Enter item name: ");
                    scanf("%s", it[itc].na);
                    printf("Enter item price: ");
                    scanf("%d", &it[itc].rs);
                    printf("Enter opening quantity: ");
                    scanf("%d", &it[itc].qty);
                    it[itc].itno = xit;
                    itc++;
                }
                break;

            case 2:
                printf("\n-- Purchase Items --\n");
                while (1) {
                    printf("Enter item number to purchase (0 to stop): ");
                    scanf("%d", &xit);
                    if (xit == 0) break;

                    int found = 0;
                    for (int j = 0; j < itc; j++) {
                        if (it[j].itno == xit) {
                            found = 1;
                            printf("Item: %s | Price: %d | Available Qty: %d\n", it[j].na, it[j].rs, it[j].qty);
                            printf("Enter quantity to purchase: ");
                            scanf("%d", &xqty);

                            if (it[j].qty + xqty > 50) {
                                printf("⚠️ Stock overflow. Cannot purchase.\n");
                            } else {
                                pur[puc] = it[j];
                                pur[puc].qty = xqty;
                                it[j].qty += xqty;
                                puc++;
                                printf("✅ Purchase recorded.\n");
                            }
                            break;
                        }
                    }
                    if (!found) printf("❌ Item not found.\n");
                }
                break;

            case 3:
                printf("\n-- Sell Items --\n");
                while (1) {
                    printf("Enter item number to sell (0 to stop): ");
                    scanf("%d", &xit);
                    if (xit == 0) break;

                    int found = 0;
                    for (int j = 0; j < itc; j++) {
                        if (it[j].itno == xit) {
                            found = 1;
                            printf("Item: %s | Price: %d | Available Qty: %d\n", it[j].na, it[j].rs, it[j].qty);
                            printf("Enter quantity to sell: ");
                            scanf("%d", &xqty);

                            if (xqty > it[j].qty || it[j].qty - xqty < 5) {
                                printf("⚠️ Insufficient stock or underflow.\n");
                            } else {
                                sal[sac] = it[j];
                                sal[sac].qty = xqty;
                                it[j].qty -= xqty;
                                sac++;
                                printf("✅ Sale recorded.\n");
                            }
                            break;
                        }
                    }
                    if (!found) printf("❌ Item not found.\n");
                }
                break;

            case 4:
                printf("\n-- Purchase Details --\n");
                printf("ItemNo\tName\tQty\tPrice\n");
                for (int j = 0; j < puc; j++) {
                    printf("%d\t%s\t%d\t%d\n", pur[j].itno, pur[j].na, pur[j].qty, pur[j].rs);
                }
                break;

            case 5:
                printf("\n-- Sales Details --\n");
                printf("ItemNo\tName\tQty\tPrice\n");
                for (int j = 0; j < sac; j++) {
                    printf("%d\t%s\t%d\t%d\n", sal[j].itno, sal[j].na, sal[j].qty, sal[j].rs);
                }
                break;

            case 6:
                printf("\n-- Current Stock --\n");
                printf("ItemNo\tName\tQty\tPrice\n");
                for (int j = 0; j < itc; j++) {
                    printf("%d\t%s\t%d\t%d\n", it[j].itno, it[j].na, it[j].qty, it[j].rs);
                }
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
