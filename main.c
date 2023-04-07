#include <stdio.h>
#include <stdlib.h>
//1.Soru: Eksik k�me eleman�. A��klama  : Ba�lang��ta 1'den n'ye kadar t�m say�lar� i�eren bir s tamsay� k�meniz var. Bir hata nedeniyle, s'deki say�lardan biri k�medeki ba�ka bir say�yla �o�alt�lm�� olsun, bu da bir say�n�n tekrarlanmas�na ve ba�ka bir say�n�n kaybolmas�na neden olur.�ki kez olu�an say�y� ve eksik olan say�y� bulun ve bunlar� bir dizi bi�iminde d�nd�r�n.   

int* eksik_ve_tekrar_eden_sayi(int* s, int n) {  // parametre olarak bir dizi ve dizinin boyutunu almasi i�in bu fonksiyon olusturdum
    int i, numara1 = -1, eksikNumara, *sonucc; // i degiskeni, numara bir degiskeni ve degerini -1, eksik numara icin eksikNumara degiskenini ve sonuc icin *sonuc pointer olusturdum.
    int* sayac = (int*) calloc(n, sizeof(int)); //calloc parametresiyle n tamsay�l�k bir dizi ayirdim ve sayac degiskenine atadim. n �ge say�s� ve sizeof ile de �ge boyutunu bayt cinsinden belirttim.
    for (i = 0; i < n; i++) {  //for dongusuyle i=0 dan, i kucuk n olana kadar iyi bir bir artir.
        sayac[s[i]-1]++; //nums[i] eleman�n�n say�s�, sayac[nums[i]-1] indeksinde tuttum.
    }
    for (i = 0; i < n; i++) { //for dongusuyle i=0 dan, i kucuk c olana kadar iyi bir bir artir.
        if (sayac[i] == 0) { //sayac dizisinin  1.indeksindeki sayinin sifira esit olup olmadi�ini kontrol eder.
            eksikNumara = i + 1; //eksikNumara de�i�kenine i+1 atanarak eksik say� belirlenmi�tir.
        } else if (sayac[i] == 2) {  //sayac dizisinin i dizinindeki degerin 2ye esit olup olmad�g�n� kontrol eder.
            if (numara1 == -1) {  // eger numara1 -1e esitse 
                numara1 = i + 1; // numara1'i (i + 1) e esitle
            } 
               
        }
    }
    sonucc = (int*) malloc(3 * sizeof(int)); //boyutu 3 olan bir tamsayi dizisini tahsis eder ve dizinin ilk ogesine bir isaretci dondurur  ve sonuc degiskenine atar. Yani eksik sayi ve tekrarlanan sayilarin sonuclarini saklar.
    sonucc[0] = eksikNumara; //sonuc dizisinin ilk elemanina eksikNumara degerini atar.
    sonucc[1] = numara1; //sonuc dizisinin ikinci elemanina numara 1 degerini atar
    return sonucc; // fonksiyonun icinde sonuc dondur.
}

int main() {
    int n, i, *s, *sonucc; // tamsayi turunde degisken ve pointer olusturdum.
    printf("Dizinin kac boyutlu oldugunu giriniz: "); // ekrana bilgi yazdirir.
    scanf("%d", &n);  //kullanicidan deger alir.
    printf("\n"); //bosluk
    s = (int*) malloc(n * sizeof(int)); // malloc paremetresini kulanarak  c boyutunda bir tamsayi dizisini ayirir. sizeof ile ayrilmasi gereken dizi boytunu ifade eder.Malloc islevi dizinin ilk ogesine bir isaretci dondurur ve daha sonra s isaretcisine atanir.
    printf("BILGILENDIRME 1: Elemanin birini soruda belirtildigi gibi hata sonucu iki kez yazilmasi gerektigi ve bundan dolayi sizinde dizinin elemanindan birini iki kez yazmaniz gerekmektedir. ");
	printf("\n"); //bosluk
    printf("\n"); //bosluk
	printf("BILGILENDIRME 2: Dizinin birinci elemanini girmeniz, girdikten sonra enter tusuna basarak diger elemaninini girmeniz gerekmektedir. Bu islemi diziniz kac elemanliysa o kadar tekrar ediniz. Son elemaninizi girdikten sonra enter tusuna basinca sonucunuz ekrana yazilacaktir.");// ekrana bilgi yazdirir.
   	printf("\n"); //bosluk
    printf("\n"); //bosluk
    printf("ornek: boyut=6 ; elemanlar= 1 2 3 4 4 5 gibi");
	printf("\n"); //bosluk
    printf("\n"); //bosluk
    printf("Dizinin elemanlarini giriniz: "); // ekrana bilgi yazdirir.
    for (i = 0; i < n; i++) { //for dongusuyle i=0 dan, i kucuk c olana kadar iyi bir bir artir.
        scanf("%d", &s[i]); // eleman sayisini alir.
    }
    sonucc = eksik_ve_tekrar_eden_sayi(s, n); // yukaridaki fonksiyonu cagirdim ve sonuc degiskenine atadim.
    printf("Eksik sayi: %d, Tekrar eden sayilar: %d", sonucc[0], sonucc[1]); //ekrana sonucu yazdirir.
    free(s); //tahsis edilen bellegi bosaltir.
    free(sonucc);//tahsis edilen bellegi bosaltir.
    return 0;
}
