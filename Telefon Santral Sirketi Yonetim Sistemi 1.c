#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#define CIKARMA 100

// aboneler.dat dosyasindaki verileri tutan struct yapisi.
struct aboneVerisi{
    char adiSoyadi[26];
    char birimAdi[31];
    int aboneTipi;
    int onOdenmisKontor;
};

// gorusmeler.txt dosyasindaki verileri tutan struct yapisi.
struct gorusmeVerisi{
int arayanDahiliNo;
char arananDisNo[11];
int gun;
int baslangicSaat;
int baslangicDakika;
int sure;
};

//struct yapilarini degiskene tanimlayan typedefler.
typedef struct aboneVerisi abone;
typedef struct gorusmeVerisi gorusme;

//Fonksiyon prototipleri.
void getAboneTipi(int);
void aboneBilgisiListeleme(FILE *);
void aboneBilgisi_disHatGorusmeleri(FILE *,FILE *);
void birBirimdekiAboneleriListeleme(FILE *);
void aboneTipineGoreSayilar_yuzdeler(FILE *);
void birGunYapilanGorusmeler(FILE *,FILE*);
void guneGoreGorusmeSayilari(FILE *);
void kontorYuklemesiGerekenAboneler(FILE *);
void birAboneninKontorYuklemesi(FILE *);
void disHatGorusmeKayitEkleme(FILE *,FILE *);
void yeniAboneEkleme(FILE *);
void aboneKaydiSilme(FILE *);



int main()
{
    //Dosyalar pointerlara atandi.
    FILE *cf1Ptr;
    FILE *cf2Ptr;

    //Degisken tanimi.
    int girilenDeger=0;

    //switch case ve menu bolumunu icinde bulunduran sonsuz while dongusu.
    while(1){

        printf("\nANA MENU\n");
        printf("1. Bir abonenin bilgilerinin listelenmesi\n");
        printf("2. Bir abonenin bilgilerinin ve o ay yapmis oldugu dis hat gorusmelerinin listelenmesi\n");
        printf("3. Bir birimdeki abonelerin bilgilerinin listelenmesi\n");
        printf("4. Abone tipine gore abone sayilarinin ve yuzdelerinin listelenmesi\n");
        printf("5. Bir gun yapilan gorusmelerin listelenmesi\n");
        printf("6. Gune gore gorusme sayilarinin ve surelerinin listelenmesi\n");
        printf("7. Dis hat gorusmesi yapabilmek icin kontor yuklemesi gereken abonelerin listelenmesi\n");
        printf("8. Bir abonenin kontor yuklemesi\n");
        printf("9. Yapilan dis hat gorusmelerine iliskin kayitlarin eklenmesi\n");
        printf("10. Yeni bir abonenin eklenmesi\n");
        printf("11. Bir abonenin kaydinin silinmesi\n");
        printf("12. Cikis\n");
        scanf("%d",&girilenDeger);

        //Menuden secilen degere gore islem yapmayi saglayan switch case yapisi.
        switch(girilenDeger){
            case 1:{
                if (( cf1Ptr = fopen( "aboneler.dat", "r" )) == NULL )
                    printf( "Dosya acilamadi.\n" );
                else aboneBilgisiListeleme(cf1Ptr);fclose(cf1Ptr);devam();break;
            }
            case 2:{
            if (( cf1Ptr = fopen( "aboneler.dat", "r" )) == NULL )
                printf( "Aboneler dosyasi acilamadi.\n" );
            else
            {
                if (( cf2Ptr = fopen( "gorusmeler.txt", "r" )) == NULL )
                    printf( "Gorusmeler dosyasi acilamadi.\n" );
                else aboneBilgisi_disHatGorusmeleri(cf1Ptr,cf2Ptr);}}fclose(cf1Ptr);fclose(cf2Ptr);devam();break;
            case 3:{
                if (( cf1Ptr = fopen( "aboneler.dat", "r" )) == NULL )
                    printf( "Dosya acilamadi.\n" );
                else birBirimdekiAboneleriListeleme(cf1Ptr);fclose(cf1Ptr);devam(); break;
            }
            case 4:{
                if (( cf1Ptr = fopen( "aboneler.dat", "r" )) == NULL )
                    printf( "Dosya acilamadi.\n" );
                else aboneTipineGoreSayilar_yuzdeler(cf1Ptr);fclose(cf1Ptr);devam(); break;
            }
            case 5:{
                if (( cf1Ptr = fopen( "aboneler.dat", "r" )) == NULL )
                    printf( "Aboneler dosyasi acilamadi.\n" );
                else{
                if (( cf2Ptr = fopen( "gorusmeler.txt", "r" )) == NULL )
                    printf( "Gorusmeler dosyasi acilamadi.\n" );
                else birGunYapilanGorusmeler(cf1Ptr,cf2Ptr);}fclose(cf1Ptr);fclose(cf2Ptr);devam();break;}
            case 6:{
                if (( cf2Ptr = fopen( "gorusmeler.txt", "r" )) == NULL )
                    printf( "Dosya acilamadi.\n" );
                else guneGoreGorusmeSayilari(cf2Ptr);}fclose(cf2Ptr);devam();break;
            case 7:{
                if (( cf1Ptr = fopen( "aboneler.dat", "r" )) == NULL )
                        printf( "Dosya acilamadi.\n" );
                    else kontorYuklemesiGerekenAboneler(cf1Ptr);}devam();break;
            case 8:{
                if (( cf1Ptr = fopen( "aboneler.dat", "rb+" )) == NULL )
                    printf( "Dosya acilamadi.\n" );
                else birAboneninKontorYuklemesi(cf1Ptr);fclose(cf1Ptr);devam(); break;
            }
            case 9:{

            if (( cf1Ptr = fopen( "aboneler.dat", "r" )) == NULL )
                printf( "Aboneler dosyasi acilamadi.\n" );
            else            {
                if (( cf2Ptr = fopen( "gorusmeler.txt", "a+b" )) == NULL )
                    printf( "Gorusmeler dosyasi acilamadi.\n" );
                else disHatGorusmeKayitEkleme(cf1Ptr,cf2Ptr);}fclose ( cf1Ptr );fclose ( cf2Ptr );fclose(cf1Ptr);fclose(cf2Ptr);devam();break;}
            case 10:{
                if (( cf1Ptr = fopen( "aboneler.dat", "rb+" )) == NULL )
                    printf( "Dosya acilamadi.\n" );
                else yeniAboneEkleme(cf1Ptr); fclose ( cf1Ptr );fclose(cf1Ptr);devam();break;
            }
            case 11:{
                if (( cf1Ptr = fopen( "aboneler.dat", "rb+" )) == NULL )
                    printf( "Dosya acilamadi.\n" );
                else aboneKaydiSilme(cf1Ptr); fclose ( cf1Ptr );fclose(cf1Ptr);devam();break;
            }
            case 12:exit(0);devam(); break;
        }

    }

    return 0;
}

//Abone tipi 1-2-3-4 gibi sayilar oldugundan onlari yaziya ceviren fonksiyon.
void getAboneTipi(int key) {

    switch(key) {
    case 1:
        printf("   Akademik");
        break;
    case 2:
        printf("   Idari");
        break;
    case 3:
        printf("   Yonetici");
        break;
    case 4:
        printf("   Diger");
        break;
    default:
        printf("   Bos");
    }
}

//Her islemden sonra devam etmek istemeyi soran fonksiyon.
void devam(){
    int komut;

    printf("\n\nAna Menuye donmek icin 1'e cikis icin 0'a basiniz.");
    scanf("%d",&komut);

    if(komut==1){
    } else exit(0);

}


//case1 icin abone bilgisini ekrana yazdiran fonksiyon.
void aboneBilgisiListeleme(FILE *aPtr){

    //degisken tanimi.
    int dahiliTelNo=0;
    struct aboneVerisi abone;

    printf("Bilgilerini gormek istediginiz abonenin dahili telefon numarasini giriniz:");
    scanf("%d",&dahiliTelNo);

    //dosyayi bastan okuyan ve fseek le arama yapip fread le okuma yapma.
    rewind(aPtr);
    fseek ( aPtr , ( dahiliTelNo-CIKARMA) * sizeof ( struct aboneVerisi ) , SEEK_SET ) ;
    fread(&abone,sizeof(struct aboneVerisi),1,aPtr);

    //if kosuluna uyuyorsa yazdirma yapiyor.
    if(abone.aboneTipi!=0){
        printf("\nTel No     Ad Soyad      Birimi                 Tip          Kontor" );
        printf("\n------     --------      --------------         ---          ------");
        printf("\n%d        %s      %s",dahiliTelNo,abone.adiSoyadi, abone.birimAdi);
        getAboneTipi(abone.aboneTipi);
        printf("     %d",abone.onOdenmisKontor);
    } else printf("Bu numaraya sahip bir abone bulunmamaktadir!");
}

//Abone bilgilerini ve dis hat gorusmelerini ekrana yazdiran fonksiyon.
void aboneBilgisi_disHatGorusmeleri(FILE *aPtr, FILE *bPtr){

    //malloc diskten okunacak veri kadar yer ayrilmasini sagladi.
    struct aboneVerisi *abone=(struct aboneVerisi *)malloc(sizeof ( struct aboneVerisi ));
    struct gorusmeVerisi *gorusme=(struct gorusmeVerisi *)malloc(sizeof ( struct gorusmeVerisi ));

    //Degisken tanimi.
    int dahiliTelNo=0,sayac=0,geceGorusmeSuresi=0,harcanan_kontor=0,gunduzGorusmeSuresi=0;

    printf("Bilgilerini gormek istediginiz abonenin dahili telefon numarasini giriniz:");
    scanf("%d",&dahiliTelNo);

    //rewind dosyayi bastan okumak icin.
    //fseek arama yapmak icin.
    //fread dosyadan veri okumak icin.
    rewind(aPtr);
    fseek ( aPtr , ( dahiliTelNo-CIKARMA) * sizeof ( struct aboneVerisi ) , SEEK_SET ) ;
    fread(abone,sizeof(struct aboneVerisi),1,aPtr);

    //if kosuluna uyarsa yazdirma islemleri.
    if(abone->aboneTipi!=0){

        printf("\nTel No      Ad Soyadi      Birimi             Tip      Kontor" );
        printf("\n------      ---------      ------             ---      ------");
        printf("\n%d         %s        %s",dahiliTelNo,abone->adiSoyadi, abone->birimAdi);
        getAboneTipi(abone->aboneTipi);
        printf("       %d",abone->onOdenmisKontor);
        rewind(bPtr);
        fscanf(bPtr,"%d %s %d %d %d %d",&gorusme->arayanDahiliNo,gorusme->arananDisNo,&gorusme->gun,&gorusme->baslangicSaat,&gorusme->baslangicDakika,&gorusme->sure);
        printf("\nDis Hat Gorusmeleri:");
        printf("\nAranan Tel No          Gun No          Baslangic         Bitis" );
        printf("\n-------------          ------          ---------         -----");

        //dosyadan dosya sonu belirteci gelene kadar okuma yapmak icin kullanılan while.
        //gerekli hesaplamalar icin if le kontrol edilip ona gore hesaplamalar yapildi.
        while(!feof(bPtr)){
            if(dahiliTelNo==gorusme->arayanDahiliNo){
                sayac++;
                int ekSaat=0,ekDakika=0,bitSaat=0,bitDakika=0,sayac1=0;
                ekSaat=gorusme->sure/60;
                ekDakika=gorusme->sure%60;
                bitDakika=gorusme->baslangicDakika+ekDakika;

                if(bitDakika>=60){
                bitDakika=bitDakika%60;
                sayac1++; }
                bitSaat=gorusme->baslangicSaat+ekSaat+sayac1;

                if(bitSaat>=24)

                    bitSaat=bitSaat%24;
                printf("\n%s             %d               %d:%d              %d:%d",gorusme->arananDisNo,gorusme->gun,gorusme->baslangicSaat,gorusme->baslangicDakika,bitSaat,bitDakika);

                    if(gorusme->baslangicSaat>=8 && gorusme->baslangicSaat<20)

                { if(bitSaat<20)

                {

                    gunduzGorusmeSuresi=gunduzGorusmeSuresi+gorusme->sure;
                    harcanan_kontor=harcanan_kontor+(gorusme->sure*3)+3;

                } else

                {

                harcanan_kontor=harcanan_kontor+(gorusme->baslangicDakika*3)+(bitDakika*2)+3;

                gunduzGorusmeSuresi=gunduzGorusmeSuresi+gorusme->sure;

                }

                }

                else

                { if(bitSaat>=20)

                {  geceGorusmeSuresi=geceGorusmeSuresi+gorusme->sure;

                    harcanan_kontor=harcanan_kontor+gorusme->sure*2+3;

                    } else

                    {

                harcanan_kontor=harcanan_kontor+(gorusme->baslangicDakika*2)+(bitDakika*3)+3;

                geceGorusmeSuresi=geceGorusmeSuresi+gorusme->sure;

                }

                    }

                fscanf(bPtr,"%d %s %d %d %d %d",&gorusme->arayanDahiliNo,gorusme->arananDisNo,&gorusme->gun,&gorusme->baslangicSaat,&gorusme->baslangicDakika,&gorusme->sure);

            }

            fscanf(bPtr,"%d %s %d %d %d %d",&gorusme->arayanDahiliNo,gorusme->arananDisNo,&gorusme->gun,&gorusme->baslangicSaat,&gorusme->baslangicDakika,&gorusme->sure);

        }

        printf("\n--------------------------------------------------------------");
        printf("\nToplam gorusme sayisi:%d",sayac);
        printf("\nToplam gunduz gorusme suresi:%d",gunduzGorusmeSuresi);
        printf("\nToplam gece gorusme suresi:%d",geceGorusmeSuresi);
        printf("\nToplam harcadigi kontor miktari:%d",harcanan_kontor);

            } else printf("Bu numaraya sahip bir abone bulunmamaktadir!");
}


//Birimdeki aboneleri listelemk icin kullanilan fonksiyon.
void birBirimdekiAboneleriListeleme(FILE *aPtr){

    char aranan_birim[30] = ("");

    int dahiliNo;

    //malloc ile diskten yer ayrilmasi.
    struct aboneVerisi *abone=(struct aboneVerisi *)malloc(sizeof ( struct aboneVerisi ));
    printf("Bilgilerini gormek istedigini birimin ismini giriniz:");
    fflush(stdin);
    gets(aranan_birim);
    printf("\nTel No     Ad Soyad           Birimi          Tip         Kontor" );
    printf("\n------     --------           ------          ---         ------");

    rewind(aPtr);

    //900 tane dahili tel no 3 basamakli olan aboneler icin for dongusu.
    for(dahiliNo=100;dahiliNo<=1000;dahiliNo++){

        fseek ( aPtr , ( dahiliNo-CIKARMA) * sizeof ( struct aboneVerisi ) , SEEK_SET ) ;
        fread(abone,sizeof(struct aboneVerisi),1,aPtr);

        if(strcmp(abone->birimAdi,aranan_birim)==0){

            printf("\n%d        %6s      %12s",dahiliNo,abone->adiSoyadi, abone->birimAdi);
            getAboneTipi(abone->aboneTipi);
            printf("     %d",abone->onOdenmisKontor);
        }
    }
}


//Abone tipine gore sayilari ve yuzdeleri hesaplayip yazdiran fonksiyon.
void aboneTipineGoreSayilar_yuzdeler(FILE *aPtr){

    //dizi tanimlamalari.
    //dizilerde tutulup islemler yapildi.
    struct aboneVerisi abone;
    int tip[5]={0},toplam=0,i;
    float yuzde[5]={0.0};

    //rewind dosya basi.
    //fread dosyadan veri okuma.
    rewind(aPtr);
    fread(&abone,sizeof( abone),1,aPtr);

    //do while sayesinde eksiksiz okuma.
    do{

        //if kosuluna uymaya gore abone sayilarini tutan tip dizisi +1 yapiliyor.
        if(abone.aboneTipi==1)
            tip[0]++;

        if(abone.aboneTipi==2)
            tip[1]++;

        if(abone.aboneTipi==3)
            tip[2]++;

        if(abone.aboneTipi==4)
            tip[3]++;

        if(abone.aboneTipi==0)
            tip[4]++;

        fread(&abone,sizeof( abone),1,aPtr);

    //dosya sonu belirtecine kadar okuma.
    }while(!feof(aPtr));

        for(i=0;i<=4;i++){
             toplam+=tip[i];
        }



        for(i=0;i<=4;i++){
            yuzde[i]=tip[i];
        }
        for(i=0;i<=4;i++){
        yuzde[i]=yuzde[i]/toplam*100;
        }


        //yazdirma islemleri.
        printf("\nAbone Tipi    Abone Sayisi     Yuzde");
        printf("\n----------    ------------     -----");
        printf("\nAkademik       %d               %2f",tip[0],yuzde[0]);
        printf("\nIdari          %d               %2f",tip[1],yuzde[1]);
        printf("\nYonetici       %d               %2f",tip[2],yuzde[2]);
        printf("\nDiger          %d               %2f",tip[3],yuzde[3]);
        printf("\nBos            %d             %2f",tip[4],yuzde[4]);

}

//gun gun gorusmeleri dosyadan okuyan ve yazdiran fonskiyon.
void birGunYapilanGorusmeler(FILE *aPtr, FILE *bPtr){

    //malloc la yer ayrildi.
    struct gorusmeVerisi *gorusme=(struct gorusmeVerisi *)malloc(sizeof ( struct gorusmeVerisi ));
    struct aboneVerisi *abone=(struct aboneVerisi *)malloc(sizeof ( struct aboneVerisi ));

    int gunNo,dahiliTelNo;

    //istenen gun numarasi alindi.
    printf("\nGormek istediginiz gunun numarasini giriniz:");
    scanf("%d",&gunNo);

    printf("\nBir gun yapilan gorusmeler");
    printf("\nArayan Tel No     Arayan Ad Soyad      Aranan Tel No    Baslangic    Sure");
    printf("\n-------------     ---------------      -------------    ---------    ----");
    rewind(aPtr);

    //dosya sonuna kadar okuma.
    while(!feof(bPtr)){

        //dosyadan okuma.
        fscanf(bPtr,"%d %s %d %d %d %d",&gorusme->arayanDahiliNo,gorusme->arananDisNo,&gorusme->gun,&gorusme->baslangicSaat,&gorusme->baslangicDakika,&gorusme->sure);

        //gun numarasi istenen gun numarasina esitse yazdiriliyor
        if(gunNo==gorusme->gun){

            dahiliTelNo=gorusme->arayanDahiliNo;

            rewind(aPtr);
            fseek (aPtr , ( dahiliTelNo-CIKARMA) * sizeof ( struct aboneVerisi ) , SEEK_SET ) ;
            fread(abone,sizeof(struct aboneVerisi),1,aPtr);

            printf("\n%-18d%-21s%-1s%10d:%d%10d",gorusme->arayanDahiliNo,abone->adiSoyadi,gorusme->arananDisNo,gorusme->baslangicSaat,gorusme->baslangicDakika,gorusme->sure);
        }


    }

}


//gun gun gorusme sayilari
void guneGoreGorusmeSayilari(FILE *aPtr){
    //malloc yer ayirma
    struct gorusmeVerisi *gorusme=(struct gorusmeVerisi *)malloc(sizeof ( struct gorusmeVerisi ));
    //degisken tanimlamalari
    float topGorusmeSayisi[31]={0},topGorusmeSuresi[31]={0};
    int i,topGorusmeSayisii=0;
    float ortalamaGorusmeSuresi[31]={0.0};

    printf("\nGune gore gorusme sayilarinin ve surelerinin listelenmesi");
    printf("\nGun     Top Gor Sayisi      Top Gor Suresi(dk)    Ortalama Gorusme Sayisi");
    printf("\n---     --------------      ------------------    -----------------------");

    rewind(aPtr);

    //dosya sonuna kadar okuma
    while(!feof(aPtr)){
        fscanf(aPtr,"%d %s %d %d %d %d",&gorusme->arayanDahiliNo,gorusme->arananDisNo,&gorusme->gun,&gorusme->baslangicSaat,&gorusme->baslangicDakika,&gorusme->sure);

        //her gun icin dongu
        for(i=1;i<=31;i++){

            if(i==gorusme->gun){
                topGorusmeSayisi[i-1]++;
                topGorusmeSuresi[i-1]+=gorusme->sure;
            }
        }
    }

    for(i=1;i<=31;i++){

        if(topGorusmeSayisi[i-1]!=0) {
        ortalamaGorusmeSuresi[i-1]=topGorusmeSuresi[i-1]/topGorusmeSayisi[i-1];
        }
    }
    for(i=1;i<=31;i++){
        printf("\n%d%15.0f%20.0f%25.2f",i,topGorusmeSayisi[i-1],topGorusmeSuresi[i-1],ortalamaGorusmeSuresi[i-1]);
    }
}

//kontor yuklemesi gereken aboneleri bulup gosteren fonksiyon
void kontorYuklemesiGerekenAboneler(FILE *aPtr){
    struct aboneVerisi abone;
    int sayac=0;

    //yazdirmalar
    printf("\nDis hat gorusmesi yapabilmek icin kontor yuklemesi gereken aboneler");
    printf("\n-------------------------------------------------------------------");
    rewind(aPtr);
    printf("\nTel No    Ad Soyad        Birimi                  Tip        Kontor");
    printf("\n------    ---------       ----------------        ----       -------");
    while(!feof(aPtr)){
        sayac++;

        fread(&abone,sizeof( abone),1,aPtr);
        if(abone.onOdenmisKontor<-100){
            printf("\n%d       %s           %s",(sayac+99),abone.adiSoyadi, abone.birimAdi);
            getAboneTipi(abone.aboneTipi);
            printf("             %d",abone.onOdenmisKontor);

        }

    }
}


//kontor yuklemesi yapilmak istenen aboneyi bulup kontor eklemesi yapan fonksiyon
void birAboneninKontorYuklemesi(FILE *aPtr){
    struct aboneVerisi abone;
    int dahiliTelefonNum,kont;



    printf("kontor yuklemek istediginiz numarayi giriniz:\n");
    scanf("%d",&dahiliTelefonNum);

    fseek ( aPtr , ( dahiliTelefonNum-CIKARMA) * sizeof ( struct aboneVerisi ) , SEEK_SET ) ;
    fread(&abone,sizeof(abone),1,aPtr);

    //if kosulu saglaniyorsa yuklenecek kontor miktari isteniyor
    if(abone.aboneTipi!=0){

        printf("yuklenecek kontor miktarini giriniz:\n");
        scanf("%d",&kont);
        abone.onOdenmisKontor+=kont;
        fseek ( aPtr , ( dahiliTelefonNum-CIKARMA) * sizeof ( struct aboneVerisi ) , SEEK_SET ) ;
        fwrite(&abone,sizeof(abone),1,aPtr);
        printf("yukleme islemi gerceklestirildi\n");
    }

        else{

            printf("bu numaraya kayýtlý abone bulunmamaktadir\n");

        }

fclose(aPtr);
}


//dis hat kayit ekleme
void disHatGorusmeKayitEkleme(FILE *aPtr, FILE *bPtr){
    int dahiliTelNo;
    struct aboneVerisi *abone=(struct aboneVerisi *)malloc(sizeof ( struct aboneVerisi ));
    struct gorusmeVerisi *gorusme=(struct gorusmeVerisi *)malloc(sizeof ( struct gorusmeVerisi ));
    printf("\nYapilan dis hat gorusmelerine iliskin kayitlarin eklenmesi");
    printf("\n----------------------------------------------------------");
    printf("\nKayit eklemek istediginiz dahili telefon numarasini giriniz:");
    scanf("%d",&dahiliTelNo);

    rewind(aPtr);
    fseek ( aPtr , ( dahiliTelNo-CIKARMA) * sizeof ( struct aboneVerisi ) , SEEK_SET ) ;
    fread(abone,sizeof(struct aboneVerisi),1,aPtr);

    if(abone->aboneTipi!=0){

        if(abone->onOdenmisKontor>-100){
            printf("Aranan dis hat numarasini giriniz:");
            scanf("%s",gorusme->arananDisNo);
            printf("Gorusmenin gununu giriniz:");
            scanf("%d",&gorusme->gun);
            printf("Gorusmenin baslangic saatini giriniz:");
            scanf("%d",&gorusme->baslangicSaat);
            printf("Gorusmenin baslangic dakikasini giriniz:");
            scanf("%d",&gorusme->baslangicDakika);
            printf("Gorusmenin suresini giriniz:");
            scanf("%d",&gorusme->sure);
            fprintf(bPtr,"%d %s %d %d %d %d",dahiliTelNo,gorusme->arananDisNo,gorusme->gun,gorusme->baslangicSaat,gorusme->baslangicDakika,gorusme->sure);

            //kontor guncellenecek.

        } else printf("Gorusme kaydi yapmak istediginiz abonenin yeterli sayida kontoru bulunmamaktadir.");

    } else printf("Bu numaraya sahip bir abone bulunamadi.");
}


//yeni abone ekleme.
void yeniAboneEkleme(FILE* aPtr){

    struct aboneVerisi abone={"","",0,0};
    int DahilitelNo;
    printf("eklemek istediginiz abonenin numarasini giriniz:");
    scanf("%d",&DahilitelNo);
    rewind(aPtr);
    fseek ( aPtr , ( DahilitelNo-CIKARMA) * sizeof ( struct aboneVerisi ) , SEEK_SET ) ;
    fread(&abone,sizeof(abone),1,aPtr);

    if(abone.aboneTipi==0){

        //kullanicidan sirasiyla eklemek istedigi abonenin bilgileri aliniyor
        printf("Abonenin adini ve soyadini giriniz:");
        fflush(stdin);
        gets(abone.adiSoyadi);
        printf("Abonenin birimini giriniz:");
        fflush(stdin);
        gets(abone.birimAdi);
        printf("Abonenin tip giriniz:");
        scanf("%d",&abone.aboneTipi);
        printf("Abonenin on odenmis kontor sayisini giriniz:");
        scanf("%d",&abone.onOdenmisKontor);
        rewind(aPtr);
        fseek ( aPtr , ( DahilitelNo-CIKARMA) * sizeof ( struct aboneVerisi ) , SEEK_SET ) ;
        fwrite(&abone,sizeof(abone),1,aPtr);
    }

    else{

        printf("boyle bir abone zaten var.");
    }
}

//abone kaydi silme
void aboneKaydiSilme(FILE *aPtr){

    struct aboneVerisi abone;
    int dahiliNum;

    printf("Silinecek abonenin dahili telefon numarasini giriniz:");
    scanf("%d",&dahiliNum);

    fseek ( aPtr , ( dahiliNum-CIKARMA) * sizeof ( struct aboneVerisi ) , SEEK_SET ) ;
    fread(&abone,sizeof(struct aboneVerisi),1,aPtr);

    if(abone.aboneTipi!=0){

        struct aboneVerisi abone={"","",0,0};
        fseek ( aPtr , ( dahiliNum-CIKARMA) * sizeof ( struct aboneVerisi ) , SEEK_SET );
        fwrite(&abone,sizeof(struct aboneVerisi),1,aPtr);
        printf("Silme islemi basarili.");
    }
    else
    {
         printf("Boyle bir abone yok!");
    }
}
