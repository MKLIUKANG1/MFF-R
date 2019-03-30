void clear(int RxMin, int RxMax, int Rz, int RyMin, int RyMax)
{// Performs climb ladder up animation if ClimbSpot is found within defined range
// Rx = x distance to find type
// Rz = z distance to find type
// Ani = Animation to change
    void vself = getlocalvar("self");
    float x = getentityproperty(vself, "x");
    float y = getentityproperty(vself, "a");
    float z = getentityproperty(vself, "z");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    void P1;
    void P2;
    int  iEntity;                                       //Entity enumeration holder.
    int  iType;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.
    int TDir;

    float Tx;
    float Ty;
    float Tz;
    float Disx;
    float Disz;
    float Disy;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iType   = getentityproperty(vEntity, "type"); //Get target name
      vAniID  = getentityproperty(vEntity,"animationID");

      if(iType == openborconstant("TYPE_PLAYER")){
        Tx = getentityproperty(vEntity, "x");
        Ty = getentityproperty(vEntity, "a");
        Tz = getentityproperty(vEntity, "z");
        P1 = getplayerproperty(0, "entity");
        P2 = getplayerproperty(1, "entity");
        TDir = getentityproperty(vEntity, "direction");
        Disx = Tx - x;
        Disz = Tz - z;
        Disy = Ty - y;

        if(P1){
          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax){
            changeentityproperty(P1, "noaicontrol", 1);
            changeentityproperty(P1, "velocity", 0);
            performattack(P1, openborconstant("ANI_FOLLOW2"));
          }
        }

        if(P2){
          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax){
            changeentityproperty(P2, "noaicontrol", 1);
            changeentityproperty(P2, "velocity", 0);
            performattack(P2, openborconstant("ANI_FOLLOW2"));
          }
        }

        if(P1 != NULL() && getentityproperty(P1,"exists") && P2 != NULL() && getentityproperty(P2,"exists")){
          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax){
            changeentityproperty(P1, "noaicontrol", 1);
            changeentityproperty(P1, "velocity", 0);
            performattack(P1, openborconstant("ANI_FOLLOW3"));
            changeentityproperty(P2, "noaicontrol", 1);
            changeentityproperty(P2, "velocity", 0);
            performattack(P2, openborconstant("ANI_FOLLOW3"));
          }
        }
      }
    }
}

void anichange(void Ani)
{// Изменить анимацию
    void self = getlocalvar("self");

    changeentityproperty(self, "animation", openborconstant(Ani)); //Сменить анимацию
}