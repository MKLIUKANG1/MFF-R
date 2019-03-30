
void bind(int null, float x, float z, float y, int dir){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "opponent");
	if(null == 1)
	{
		bindentity(opp, self, x, z, y, dir, 0);
	}
	else if(null == 0)
	{
		bindentity(opp, NULL());
	}
}

void bind2(int null, float x, float z, float y, int dir){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "grabbing");
	if(null == 1)
	{
		bindentity(opp, self, x, z, y, dir, 0);
	}
	else if(null == 0)
	{
		bindentity(opp, NULL());
	}
}

void forceanim(int anim){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "opponent");
	changeentityproperty(opp, "animation", anim);
}

void forceanim2(int anim){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "grabbing");
	changeentityproperty(opp, "animation", anim);
}

void beidle()
{//Пойдойти к анимаций IDLE!
    void self = getlocalvar("self");

    setidle(self);
}

void block(int Flag)
{//Становится блокировкой статуса
    void self = getlocalvar("self");
    changeentityproperty(self, "aiflag", "blocking", Flag);
}

void Join(int Flag)
{//Повороты Присоединяются к статусу
    changeopenborvariant("nojoin", Flag);
}

void degravity(int Ratio)
{// Изменить эффект антигравитаций
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void stwall(int Ratio, int Ratio2, int Ratio3)
{// Изменить эффект антигравитаций
    void self = getlocalvar("self");
    changeentityproperty(self, "subject_to_wall", Ratio);
    changeentityproperty(self, "subject_to_hole", Ratio2);
    changeentityproperty(self, "subject_to_gravity", Ratio3);
}

void blink()
{// Изменить эффект антигравитаций
    void self = getlocalvar("self");
    int eTime = openborvariant("elapsed_time");
    changeentityproperty(self, "invincible", 1);
    changeentityproperty(self, "invinctime", eTime + 340);
    changeentityproperty(self, "blink", 1);
}

void direc(int Ratio)
{// Изменить эффект антигравитаций
    void self = getlocalvar("self");
    changeentityproperty(self, "direction", Ratio);
}

void move(int dx, int dz,int da)
{ // Перемещяет сущность (Entity) свободно или игнорирует
    void self = getlocalvar("self");
    int x = getentityproperty(self,"x"); 			// Получите координаты персонажа по Х
    int z = getentityproperty(self,"z"); 			// Получите координаты персонажа по Z
    int a = getentityproperty(self,"a"); 			// Получите координаты персонажа по A
    int dir = getentityproperty(self,"direction"); // Получить обратное направление персонажа

     if(dir==0){ // Лицом слева?
      changeentityproperty(self, "position", x-dx, z+dz, a+da); //Движение
     }
     else if(dir==1){ // Лицом справа?
      changeentityproperty(self, "position", x+dx, z+dz, a+da); //Движение
     }
}

void slamstart()
{// Используйте финиш после использования этого
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL4")); // Slam Starter
   }
}

void slamstart2()
{
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL5")); // Slam Starter
   }
}

void slamstart3()
{
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL6")); // Slam Starter
   }
}

void slamstart5()
{
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7")); // Slam Starter
   }
}

void position(int Frame, float dx, float dy, float dz, int face)
{ // Изменить позицию захваченного объекта относительно захвачика
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     updateframe(target, Frame);
     bindentity(target, self, dx, dz, dy, face, 0);
   }
}

void slamstart4(int dx, int dy, int dz)
{
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }

   if(target!=NULL()){
     int Tx = getentityproperty(target, "x");
     int Tz = getentityproperty(target, "z");
     int Ty = getentityproperty(target, "a");
     changeentityproperty(self, "position", Tx+dx, Tz+dz, Ty+dy); //Teleport to target!
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL20")); // Slam Starter
   }
}

void depost(int Gr)
{// Release grabbed entity // Выпуск захваченного объекта
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     bindentity(target, NULL());

     if(Gr == 1)
     {
       int x = getentityproperty(target, "x");
       int z = getentityproperty(target, "z");
       changeentityproperty(target, "position", x, z, 0);
     }
   }
}

void depost2(int Damage, int Type, int Gr, int Stay)
{// Release grabbed entity // Выпуск захваченного объекта
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     bindentity(target, NULL());

     if(Type==1)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL20")); // 1ый Finisher
     }

     if(Type==2)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL21")); // 1ый Finisher
     }

     if(Gr == 1)
     {
       int x = getentityproperty(target, "x");
       int z = getentityproperty(target, "z");
       changeentityproperty(target, "position", x, z, 0);
       changeentityproperty(target, "staydown", "rise", Stay); 
     }
   }
}

void antiwall2(int Dist, int Move, int Distz)
{// Проверяет, есть ли стена на определенном расстоянии
// Если есть стена, объект будет отодвинут с определенным движением
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if (Direction == 0){ //Объект, стоящий слева?                 
      Dist = -Dist; //Reverse Dist to match facing // Реверс дистанций для соответствия облицовки
      Move = -Move; //Reverse Move to match facing // Реверс движения для соответсвия облицовки
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > 0)
   {
     changeentityproperty(self, "position", x, z-Distz);
     changeentityproperty(self, "velocity", 0, 0, 0); //Остановить движения!
   }

   if(H > 0)
   {
     changeentityproperty(self, "position", x+Move);
     changeentityproperty(self, "velocity", 0, 0, 0); //Остановить движения!
   }
}

void finish(int Damage, int Type, int x, int y, int z, int Face)
{ // Повреждение в качестве шлема или броска
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){
       MDir = SDir;
   }

   if(Face==1){

     if(SDir==0){
       MDir = 1;
     } else { MDir = 0;}
   }

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int dir = getentityproperty(target,"direction"); //Обратить внимания на сторону противника
     if(dir==0){ // Лицом влево?
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL")); // 1ый Finisher
     }

     if(Type==2)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL9")); // 2ой Finisher
     }

     tossentity(target, y, x, z); // Бросить оппонента ;)
     changeentityproperty(target, "direction", MDir);
   }
}

void throw(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as throw finisher
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){
       MDir = SDir;
   }

   if(Face==1){

     if(SDir==0){
       MDir = 1;
     } else { MDir = 0;}
   }

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int dir = getentityproperty(target,"direction");
     if(dir==0){
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL1"));
     }

     if(Type==2)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL4"));
     }

     if(Type==3)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL5"));
     }

     changeentityproperty(target, "attacking", 1);
     changeentityproperty(target, "damage_on_landing", Damage);
     changeentityproperty(target, "projectile", 1);
     changeentityproperty(target, "direction", MDir);
     tossentity(target, y, x, z);
   }
}

void slammed(int Damage)
{
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health");
    if(Health >= Damage){
      damageentity(self, self, Damage, 1, openborconstant("ATK_NORMAL9"));
    } else if(Health > 0 && Health < Damage){
      damageentity(self, self, Health, 1, openborconstant("ATK_NORMAL9"));
    } 
    tossentity(self, 0, 0, 0);
}

void stop()
{// Stop hero's movement!
    void self = getlocalvar("self");
    changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
}

void stopz()
{
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vy = getlocalvar("y"+self);
    changeentityproperty(self, "velocity", Vx, 0, Vy); //Stop moving!
}

void leaper( float Vx, float Vy, float Vz )
{
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){
      Vx = -Vx ;
    }

    tossentity(self, Vy, Vx, Vz); //Leap!
}

void nomoveidle2(void Ani)
{
    void self = getlocalvar("self");
    int iPIndex = getentityproperty(self,"playerindex");
    void iRKeyL = playerkeys(iPIndex, 0, "moveleft");
    void iRKeyR = playerkeys(iPIndex, 0, "moveright");

    if (!iRKeyL&&!iRKeyR){
      stop();
      performattack(self, openborconstant(Ani));
    }
}

void clearL()
{// Clears all local variables
     clearlocalvar();
}

void dasher( float Vx, float Vy, float Vz )
{
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){
      Vx = -Vx ;
    }

    changeentityproperty(self, "velocity", Vx, Vz, Vy);
}



void hurt4(int Damage)
{
    void self = getlocalvar("self");
    int Health = getentityproperty(self,"health");
     
    changeentityproperty(self, "health", Health - Damage);
}

void finisher(void AniP, void Ani , int RxMin, int RxMax, int Rz, int Type, int Flag)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");
    void vEntity;
    int  iEntity;
    int  iType;
    int  iMax      = openborvariant("ent_max");

    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);
      iType   = getentityproperty(vEntity, "type");

      if (iType == openborconstant("TYPE_ENEMY")){
        float Tx = getentityproperty(vEntity, "x");
	float Tz = getentityproperty(vEntity, "z");
        int Anti = getentityproperty(vEntity, "antigrab");
        int Edir = getentityproperty(vEntity, "direction");
	void EAnim = getentityproperty(vEntity, "animationID");

        if(EAnim == openborconstant(AniP)){
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx >= RxMin && Disx <= RxMax && Disz <= Rz && dir == 1 )
      {
        if(Type == 2){
          if(((Flag == 1 && Edir == 0) || Flag == 0) && Anti < 10){
            dasher(0,0,0);
            setlocalvar("Target" + self, vEntity);
            performattack(self, openborconstant(Ani));
          }
        } else {
          if((Flag == 1 && Edir == 0) || Flag == 0){
            if(Type == 1){
              dasher(0,0,0);
              setlocalvar("Target" + self, vEntity);
            }
            performattack(self, openborconstant(Ani));
          }
        }
      } else if( Disx >= -RxMax && Disx <= -RxMin && Disz <= Rz && dir == 0)
      {
        if(Type == 2){
          if(((Flag == 1 && Edir == 1) || Flag == 0) && Anti < 10){
            dasher(0,0,0);
            setlocalvar("Target" + self, vEntity);
            performattack(self, openborconstant(Ani));
          }
        } else {
          if((Flag == 1 && Edir == 1) || Flag == 0){
            if(Type == 1){
              dasher(0,0,0);
              setlocalvar("Target" + self, vEntity);
            }
            performattack(self, openborconstant(Ani));
          }
        }
      }
        }
      }
    }
}

void finisher3(void AniNPC, void Ani , int RxMin, int RxMax, int Rz, int Type, int Flag)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");
    void vEntity;
    int  iEntity;
    int  iType;
    int  iMax      = openborvariant("ent_max");

    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);
      iType   = getentityproperty(vEntity, "type");

      if (iType == openborconstant("TYPE_NPC")){
        float Tx = getentityproperty(vEntity, "x");
	float Tz = getentityproperty(vEntity, "z");
        int Anti = getentityproperty(vEntity, "antigrab");
        int Edir = getentityproperty(vEntity, "direction");
	void EAnim = getentityproperty(vEntity, "animationID");

        if(EAnim == openborconstant(AniNPC)){
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx >= RxMin && Disx <= RxMax && Disz <= Rz && dir == 1 )
      {
        if(Type == 2){
          if(((Flag == 1 && Edir == 0) || Flag == 0) && Anti < 10){
            dasher(0,0,0);
            setlocalvar("Target" + self, vEntity);
            performattack(self, openborconstant(Ani));
          }
        } else {
          if((Flag == 1 && Edir == 0) || Flag == 0){
            if(Type == 1){
              dasher(0,0,0);
              setlocalvar("Target" + self, vEntity);
            }
            performattack(self, openborconstant(Ani));
          }
        }
      } else if( Disx >= -RxMax && Disx <= -RxMin && Disz <= Rz && dir == 0)
      {
        if(Type == 2){
          if(((Flag == 1 && Edir == 1) || Flag == 0) && Anti < 10){
            dasher(0,0,0);
            setlocalvar("Target" + self, vEntity);
            performattack(self, openborconstant(Ani));
          }
        } else {
          if((Flag == 1 && Edir == 1) || Flag == 0){
            if(Type == 1){
              dasher(0,0,0);
              setlocalvar("Target" + self, vEntity);
            }
            performattack(self, openborconstant(Ani));
          }
        }
      }
        }
      }
    }
}

void shoot(void Shot, float dx, float dy, float dz)
{
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   void vShot;

   if (Direction == 0){             
      dx = -dx;
   }

   vShot = projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
   return vShot;
}

void keyflip(int Inv)
{
    void self = getlocalvar("self");
    int iPIndex = getentityproperty(self,"playerindex");

    if (Inv == 0){
      if (playerkeys(iPIndex, 0, "moveleft")){
        changeentityproperty(self, "direction", 0); 
      } else if (playerkeys(iPIndex, 0, "moveright")){ 
        changeentityproperty(self, "direction", 1);
      }
    } else if (Inv == 1){
      if (playerkeys(iPIndex, 0, "moveleft")){ 
        changeentityproperty(self, "direction", 1);
      } else if (playerkeys(iPIndex, 0, "moveright")){ 
        changeentityproperty(self, "direction", 0);
      }
    }
}

void kickObject(void Ani, int RxMin, int RxMax, int Rz)
{// Проверяет ближайшее оружие и диапазон
    void self = getlocalvar("self");			//Вызвать.
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    float b = getentityproperty(self, "base");
    int dir = getentityproperty(self, "direction");
    int iPIndex = getentityproperty(self,"playerindex");
    void vEntity;                                       //Цель метка-заполнитель объекта.
    int  iEntity;                                       //Держатель перечисления объекта.
    int  iType;                                         //Тип объекта.
    int  iMax      = openborvariant("ent_max");         //Счёт объекта

    //Перечислите и соединяйте через сбор объектов.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Получите целевой объект из текущего цикла.
      iType   = getentityproperty(vEntity, "type"); //Получить тип цели.

      //Тип оружия?
      if (iType == openborconstant("TYPE_ITEM")){
        float Tx = getentityproperty(vEntity, "x");
        float Ty = getentityproperty(vEntity, "a");
	float Tz = getentityproperty(vEntity, "z");
	void IName = getentityproperty(vEntity, "name");

        if((IName == "barel" || IName == "box" || IName == "rock" || IName == "wood" || IName == "boxx" || IName == "ball") && Ty == b){
          float Disx = Tx - x;
          float Disz = Tz - z;

          if(Disz < 0){
            Disz = -Disz;
          }

          if( (Disx >= RxMin && Disx <= RxMax && Disz <= Rz && dir == 1) || (Disx >= -RxMax && Disx <= -RxMin && Disz <= Rz && dir == 0)){
            dasher(0,0,0);
            setlocalvar("Object" + self, vEntity);
            setlocalvar("Target" + self, IName);
            performattack(self, openborconstant(Ani));
          }
        }
      }
    }
}

void shootObject(float fX, float fY, float fZ, float Vx, float Vy, float Vz)
{
    void self = getlocalvar("self");
    void Object = getlocalvar("Object" + self);
    void Name = getlocalvar("Target" + self);
    void Shot;

    if(Name == "barel"){
      Shot = "barel2";
    } else if(Name == "box"){
      Shot = "box2";
    } else if(Name == "rock"){
      Shot = "rock2";
    } else if(Name == "wood"){
      Shot = "wood2";
    } else if(Name == "boxx"){
      Shot = "boxx2";
    } else if(Name == "ball"){
      Shot = "ball2";
    }

    shooter2(Shot, fX, fY, fZ, Vx, Vy, Vz);
    killentity(Object);

    setlocalvar("Object" + self, NULL());
    setlocalvar("Target" + self, NULL());
}

void keyint(void Ani, int Frame, void Key, int Hflag)
{
    void self = getlocalvar("self");   
    int iPIndex = getentityproperty(self,"playerindex");
    void iRKey;

      if (Key=="U"){
       iRKey = playerkeys(iPIndex, 0, "moveup"); // "Up"
	}

      if (Key=="D"){
        iRKey = playerkeys(iPIndex, 0, "movedown"); // "Down"
	}

      if (Key=="J"){
        iRKey = playerkeys(iPIndex, 0, "jump"); // "Jump"
	}

      if (Key=="A"){
        iRKey = playerkeys(iPIndex, 0, "attack"); // "Attack"
	}

      if (Key=="A2"){
        iRKey = playerkeys(iPIndex, 0, "attack2"); // "Attack2"
	}

      if (Key=="S"){
        iRKey = playerkeys(iPIndex, 0, "special"); // "Special"
	}

      if (Hflag==1){
        iRKey = !iRKey; 
	}
}

void kickreact(int RxMin, int RxMax, int Ry, int Rz, void EAni)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");
    void target = findtarget(self);

    if(target!=NULL()){
      void PAnim = getentityproperty(target, "animationID");
      float Tx = getentityproperty(target, "x");
      float Ty = getentityproperty(target, "a");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disy = Ty - y;
      float Disz = Tz - z;

      if(Disy < 0){
        Disy = -Disy;
      }

      if(Disz < 0){
        Disz = -Disz;
      }

      if(PAnim == openborconstant("ANI_FOLLOW46") || PAnim == openborconstant("ANI_FOLLOW47") || PAnim == openborconstant("ANI_PAIN7") || PAnim == openborconstant("ANI_PAIN17") || PAnim == openborconstant("ANI_PAIN18") || PAnim == openborconstant("ANI_PAIN19") || PAnim == openborconstant("ANI_FREESPECIAL22") || PAnim == openborconstant("ANI_FREESPECIAL23")){
        if( Disx >= RxMin && Disx <= RxMax && Disy <= Ry && Disz <= Rz && dir == 1){
          performattack(self, openborconstant(EAni));
        } else if(Disx >= -RxMax && Disx <= -RxMin && Disy <= Ry && Disz <= Rz && dir == 0){
          performattack(self, openborconstant(EAni));
        }
      }
    }
}

void nograb(int Flag)
{// Повороты grabbable статус
    void self = getlocalvar("self");
    changeentityproperty(self, "nograb", Flag);
}

void anichange(void Ani)
{// Изменить анимацию
    void self = getlocalvar("self");

    changeentityproperty(self, "animation", openborconstant(Ani)); //Сменить анимацию
}

void hurt(int Damage)
{
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     void THealth = getentityproperty(target,"health");
     if(THealth > Damage)
     {
       changeentityproperty(target, "health", THealth - Damage);
     } else {
       changeentityproperty(target, "health", 1);
     }
   }
}

void hurt2(int Damage)
{
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int THealth = getentityproperty(target,"health");
     int TAniPos = getentityproperty(target,"animpos");
     if(THealth > Damage)
     {
       damageentity(target, self, Damage, 0, openborconstant("ATK_NORMAL7"));
       updateframe(target, TAniPos);
     } else {
       int Damage2 = THealth - 1;
       damageentity(target, self, Damage2, 0, openborconstant("ATK_NORMAL7"));
       updateframe(target, TAniPos);
     }
   }
}


void keymove(float Vx, float Vz)
{
      void self = getlocalvar("self");
      int iPIndex = getentityproperty(self,"playerindex");
      float xdir = 0;

      if (playerkeys(iPIndex, 0, "moveleft")){
	  xdir = -Vx;
      } else if(playerkeys(iPIndex, 0, "moveright")){
	  xdir = Vx;
      }

      if (playerkeys(iPIndex, 0, "moveleft", "moveright")){
	  xdir = 0;
      }

      changeentityproperty(self, "velocity", xdir, 0);
}

void spawn01(void vName, float fX, float fY, float fZ)
{

	void self = getlocalvar("self");
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName);

	if (iDirection == 0){             
          fX = -fX; 
	}

      fX = fX + getentityproperty(self, "x"); 
      fY = fY + getentityproperty(self, "a"); 
      fZ = fZ + getentityproperty(self, "z"); 
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); 
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
    
	return vSpawn; //Return spawn.
}

void spawnbind(void Name, float dx, float dy, float dz)
{ // Spawn and bind other entity
   void self = getlocalvar("self");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, 0);
   bindentity(Spawn, self, dx, dz, dy, 0, 0);
}

void spawnbind2(void Name1, void Name2, float dx, float dy, float dz)
{ // Spawn and bind other entity
   void P1 = getplayerproperty(0, "entity");
   void P2 = getplayerproperty(1, "entity");
   void vAniID1 = getentityproperty(P1,"animationID");
   void vAniID2 = getentityproperty(P2,"animationID");
   void Spawn;

   if(P1 && vAniID1 == openborconstant("ANI_SPAWN") || vAniID1 == openborconstant("ANI_RESPAWN") || vAniID1 == openborconstant("ANI_FREESPECIAL26") || vAniID1 == openborconstant("ANI_FREESPECIAL27") || vAniID1 == openborconstant("ANI_FREESPECIAL28") || vAniID1 == openborconstant("ANI_FREESPECIAL29") || vAniID1 == openborconstant("ANI_FREESPECIAL30") || vAniID1 == openborconstant("ANI_FREESPECIAL31") || vAniID1 == openborconstant("ANI_FREESPECIAL32") || vAniID1 == openborconstant("ANI_FREESPECIAL33") || vAniID1 == openborconstant("ANI_FREESPECIAL34")){
     Spawn = spawn01(Name1, dx, dy, 0);
     bindentity(Spawn, P1, dx, dz, dy, 0, 0);
   }

   if(P2 && vAniID2 == openborconstant("ANI_SPAWN") || vAniID2 == openborconstant("ANI_RESPAWN") || vAniID2 == openborconstant("ANI_FREESPECIAL26") || vAniID2 == openborconstant("ANI_FREESPECIAL27") || vAniID2 == openborconstant("ANI_FREESPECIAL28") || vAniID2 == openborconstant("ANI_FREESPECIAL29") || vAniID2 == openborconstant("ANI_FREESPECIAL30") || vAniID2 == openborconstant("ANI_FREESPECIAL31") || vAniID2 == openborconstant("ANI_FREESPECIAL32") || vAniID2 == openborconstant("ANI_FREESPECIAL33") || vAniID2 == openborconstant("ANI_FREESPECIAL34")){
     Spawn = spawn01(Name2, dx, dy, 0);
     bindentity(Spawn, P2, dx, dz, dy, 0, 0);
   }
}

void entergrab()
{
    void self = getlocalvar("self");

    changeentityproperty(self, "aiflag", "jumping", 0); // Disable jumping status
    changeentityproperty(self, "aiflag", "attacking", 1); // Enable attacking status

    changeentityproperty(self, "takeaction", "common_grabattack"); // Enters grabattack
}

void shooter2(void vName, float fX, float fY, float fZ, float Vx, float Vy, float Vz)
{
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   void vSpawn;
	
   vSpawn = spawn01(vName, fX, fY, fZ);
   if (Direction == 0){                
      Vx = -Vx;
   }

   changeentityproperty(vSpawn, "velocity", Vx, Vz, Vy);
}

void basechange(void Ani)
{
    void self = getlocalvar("self");
    int y = getentityproperty(self,"a");
    int b = getentityproperty(self, "base");

    if( y <= 1+b ){
      performattack(self, openborconstant(Ani));
    }
}

void attack1(int RxMin, int RxMax, int Rz, void Ani)
{
    void self = getlocalvar("self");
    void target = findtarget(self);
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx >= RxMin && Disx <= RxMax && Disz <= Rz && dir == 1)
      {
        performattack(self, openborconstant(Ani));
      } else if( Disx >= -RxMax && Disx <= -RxMin && Disz <= Rz && dir == 0)
      {
        performattack(self, openborconstant(Ani));
      }
    }
}

void attack3(int RxMin, int RxMax, int RyMin, int RyMax, int Rz, void Ani)
{
    void self = getlocalvar("self");
    void target = findtarget(self);
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Ty = getentityproperty(target, "a");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disy = Ty - y;
      float Disz = Tz - z;

      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx >= RxMin && Disx <= RxMax && Disy >= RyMin && Disy <= RyMax && Disz <= Rz && dir == 1)
      {
        performattack(self, openborconstant(Ani));
      } else if( Disx >= -RxMax && Disx <= -RxMin && Disy >= RyMin && Disy <= RyMax && Disz <= Rz && dir == 0)
      {
        performattack(self, openborconstant(Ani));
      }
    }
}

void teletarget(int dx, int dy, int dz)
{
    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");
    int dir = getentityproperty(self, "direction");

    if(dir==0){
      dx = -dx ;
    }

    if(target!=NULL()){
      int Tx = getentityproperty(target, "x");
      int Tz = getentityproperty(target, "z");

      changeentityproperty(self, "position", Tx+dx, Tz+dz, dy);
    } 
}

void attackoff(void Ani)
{
    void self = getlocalvar("self");
    void target = findtarget(self);
    int Dir = getentityproperty(self,"direction");
    int TDir = getentityproperty(target,"direction");

    if(target!=NULL()){
      void PAnim = getentityproperty(target, "animationID");

      if(PAnim == openborconstant("ANI_FOLLOW46") && Dir == 0){
        performattack(self, openborconstant(Ani));
      }
    }
}

void attackoff2(void Ani)
{
    void self = getlocalvar("self");
    void target = findtarget(self);
    int Dir = getentityproperty(self,"direction");
    int TDir = getentityproperty(target,"direction");

    if(target!=NULL()){
      void PAnim = getentityproperty(target, "animationID");

      if(PAnim == openborconstant("ANI_FOLLOW46") || PAnim == openborconstant("ANI_FOLLOW47") || PAnim == openborconstant("ANI_PAIN7") || PAnim == openborconstant("ANI_PAIN17") || PAnim == openborconstant("ANI_PAIN18") || PAnim == openborconstant("ANI_PAIN19") && Dir == TDir){
        performattack(self, openborconstant(Ani));
      }
    }
}

void attackgrd(int RxMin, int RxMax, int RaMin, int RaMax, int Rz, void Ani, void Ani2)
{
    void self = getlocalvar("self");
    void target = findtarget(self);
    float x = getentityproperty(self, "x");
    float a = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Ta = getentityproperty(target, "a");
      float Tz = getentityproperty(target, "z");
      float dir2 = getentityproperty(target, "direction");

      float Disx = Tx - x;
      float Disa = Ta - a;
      float Disz = Tz - z;

      if(Disz < 0){
        Disz = -Disz;
      }

      if( getentityproperty(target, "animationID") == openborconstant(Ani2) && Disx >= RxMin && Disx <= RxMax && Disa >= RaMin && Disa <= RaMax && Disz <= Rz && dir == 1 && dir2 == 0)
      {
        performattack(self, openborconstant(Ani));


      } else if( getentityproperty(target, "animationID") == openborconstant(Ani2) && Disx >= -RxMax && Disx <= -RxMin && Disa >= RaMin && Disa <= RaMax && Disz <= Rz && dir == 0 && dir2 == 1)
      {
        performattack(self, openborconstant(Ani));
      }
    }
}

void anti()
{
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     tossentity(target, 1, 0, 0);
   }
}

void grabcheckA(void Ani1, void Ani2, void Ani3)
{
    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");

    if(target!=NULL()){

      if(getentityproperty(target, "a") > 0){
        int Check = checkgrab(target);

        if(Check == 0)
        { 
          changeentityproperty(self, "animation", openborconstant(Ani2));
        } else if(Check == 1){
          setlocalvar("Target" + self, target);
          changeentityproperty(self, "animation", openborconstant(Ani1));
        }
      } else {
        changeentityproperty(self, "animation", openborconstant(Ani3));
      }

    }
}

void grabcheckG(void Ani1, void Ani2, void Ani3)
{
    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");
    int b = getentityproperty(target, "base");
    int y = getentityproperty(target,"a");

    if(target!=NULL()){

      if(y == 0 || y <= 1+b){
        int Check = checkgrab(target);

        if(Check == 0)
        { 
          changeentityproperty(self, "animation", openborconstant(Ani2));
        } else if(Check == 1){
          setlocalvar("Target" + self, target);
          changeentityproperty(self, "animation", openborconstant(Ani1));
        }
      } else {
        changeentityproperty(self, "animation", openborconstant(Ani3));
      }

    }
}

void checkgrab(void target)
{
    if(getentityproperty(target, "type") == openborconstant("TYPE_ENEMY")){
      char Tname = getentityproperty(target, "defaultname");

      if(Tname == "Enemy_1" || Tname == "Enemy_2" || Tname == "Enemy_3" || Tname == "Enemy_4" || Tname == "Enemy_5" || Tname == "Enemy_6" )
      { 
        return 0;
      } else if(Tname == "boss1" || Tname == "boss2" || Tname == "boss3" || Tname == "Boss2-1" || Tname == "Boss___" || Tname == "boss4" || Tname == "boss4-1" )
      {
        return 0;
      } else if(Tname == "boss1" || Tname == "boss2" || Tname == "boss3" || Tname == "Boss2-1" || Tname == "Boss___" || Tname == "boss4" || Tname == "boss4-1" )
      {
        return 0;
      } else {
        return 1;
      }
    } else {
      return 0;
    }
}

void riseattack(int Rx, int Rz, void Ani)
{
    void self = getlocalvar("self");
    void target = findtarget(self);
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disx < 0){
        Disx = -Disx;
      }
      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx <= Rx && Disz <= Rz )
      {
        if(Tx < x){
          changeentityproperty(self, "direction", 0);
        } else {
          changeentityproperty(self, "direction", 1);
        }
        changeentityproperty(self, "animation", openborconstant(Ani));
      } 
    }
}

void conditionalflip2()
{
   void self = getlocalvar("self");
   void target = getentityproperty(self, "opponent");

   if(target)
   {
     int Direction = getentityproperty(self, "direction");
     int TDir = getentityproperty(target, "direction");

     if(TDir == 0 && Direction == 0){             
       changeentityproperty(self, "direction", 1);
     } else if(TDir == 1 && Direction == 1){
       changeentityproperty(self, "direction", 0);
     }
   }
}

void conditionalflip3()
{
   void self = getlocalvar("self");
   void target = getentityproperty(self, "opponent");

   if(target)
   {
     int Direction = getentityproperty(self, "direction");
     int TDir = getentityproperty(target, "direction");

     if(TDir == 1 && Direction == 1){             
       changeentityproperty(self, "direction", 0);
     } else if(TDir == 0 && Direction == 0){
       changeentityproperty(self, "direction", 1);
     }
   }
}

void conditionalflip()
{
	void self = getlocalvar("self");
	int p = getentityproperty(self, "playerindex");
	int dir = getglobalvar("p"+p+"lastdir");
	int sdir = getentityproperty(self, "direction");
	int flip;
	if(dir!=NULL() && dir!=sdir)
	{
		flip = 0;
	}
	else
	{
		flip = 1;
	}

	if(flip) {
		changeentityproperty(self, "direction", !sdir);
	}

}


void flip()
{
    void self = getlocalvar("self");
    int Direction = getentityproperty(self, "direction");

    if (Direction == 0){                
      changeentityproperty(self, "direction", 1);
    } else {
      changeentityproperty(self, "direction", 0);
    }
}


void floater( int Time )
{
    void self = getlocalvar("self");
    int eTime = openborvariant("elapsed_time");

    changeentityproperty(self, "tosstime", eTime + 2*Time);
}

void looper(int Frame, int Limit)
{
    void self = getlocalvar("self");
    void loop = getlocalvar("Loop" + self);

    if(loop==NULL()){
      setlocalvar("Loop" + self, 0);
      loop = 0;
    } 
   
    if(loop < Limit){
      setlocalvar("Loop" + self, loop+1);
      updateframe(self, Frame);
    } else if(loop==Limit){
      setlocalvar("Loop" + self, NULL());
    }
}

void pinner(void Ani , int RxMin, int RxMax, int Rz)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    float b = getentityproperty(self, "base");
    int dir = getentityproperty(self, "direction");
    int iPIndex = getentityproperty(self,"playerindex");
    void vEntity;
    int  iEntity;
    int  iType;
    int  iMax      = openborvariant("ent_max");
    void iRKey;

    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);
      iType   = getentityproperty(vEntity, "type");

      //Enemy type?
      if (iType == openborconstant("TYPE_ENEMY")){
        iRKey = playerkeys(iPIndex, 0, "movedown");
        float Tx = getentityproperty(vEntity, "x");
        float Ty = getentityproperty(vEntity, "a");
	float Tz = getentityproperty(vEntity, "z");
        int Edir = getentityproperty(vEntity, "direction");
	void EAnim = getentityproperty(vEntity, "animationID");
        int EHealth = getentityproperty(vEntity, "health");
        int Def = getentityproperty(vEntity, "defense", openborconstant("ATK_NORMAL14"));

        if((EAnim == openborconstant("ANI_FALL") || EAnim == openborconstant("ANI_FALL5") || EAnim == openborconstant("ANI_FALL7")) && Ty == b && EHealth > 0 && iRKey && Def < 5){
          float Disx = Tx - x;
          float Disz = Tz - z;

          if(Disz < 0){
            Disz = -Disz;
          }

          if( (Disx >= RxMin && Disx <= RxMax && Disz <= Rz && dir == 1 && Edir == 0 ) || (Disx >= -RxMax && Disx <= -RxMin && Disz <= Rz && dir == 0 && Edir == 1)){
            dasher(0,0,0);
            setlocalvar("Target" + self, vEntity);
            changeentityproperty(self, "position", Tx, Tz);
            performattack(self, openborconstant(Ani));
          }
        }
      }
    }
}

void clearGrab()
{
   void self = getlocalvar("self");
   setlocalvar("Target" + self, NULL());
}


void checkgrabA(void Ani, int Frame)
{
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int Def;

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
   }
   if(target!=NULL())
   {
     Def = getentityproperty(target, "defense", openborconstant("ATK_NORMAL11"));

     if(Def >= 5)
     {
       anichange(Ani, Frame);
     }
   }
}

void platform(int Flag)
{
    void self = getlocalvar("self");
    changeentityproperty(self, "Subject_to_Platform", Flag);
}

void spawnAnim(void Name, float dx, float dy, float dz, void Ani)
{
   void self = getlocalvar("self");
   int map = getentityproperty(self,"map");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, dz);
   changeentityproperty(Spawn, "animation", openborconstant(Ani));
}

/* Targetting functions */
void target(float Velx, float Velz, float dx, float dz, int Stop, int Flip)
{// Targetting opponent before leaping or dashing.
// Velx = x Velocity
// Velz = z Velocity
// dx = x added distance
// dz = z added distance
// Stop = flag to stop moving if no target is found

    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if (dir == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
    }

    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    if( getlocalvar("T"+self) != NULL()){
      void target = getlocalvar("T"+self);
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");

      if(Flip == 1){
        if(Tx < x){
          changeentityproperty(self, "direction", 0);
        } else {
          changeentityproperty(self, "direction", 1);
        }
      }

      x = x+dx;
      z = z+dz;
      float Disx = Tx - x;
      float Disz = Tz - z;

//Set both distance as positive value
      if(Disx < 0){
        Disx = -Disx;
      }

      if(Disz < 0){
        Disz = -Disz;
      }

// Calculate velocity for targetting
      if(Disz < Disx)
      {
        if(Tx < x){
          setlocalvar("x"+self, -Velx);
        } else { setlocalvar("x"+self, Velx); }

        setlocalvar("z"+self, Velx*(Tz-z)/Disx);
      } else {
        if(Tz < z){
          setlocalvar("z"+self, -Velz);
        } else { setlocalvar("z"+self, Velz); }

        setlocalvar("x"+self, Velz*(Tx-x)/Disz);
      }

    } else {
      if(Stop == 1)
      {
        setlocalvar("z"+self, 0);
        setlocalvar("x"+self, 0);
      } else {
        setlocalvar("z"+self, 0);
        if(dir==0){
          setlocalvar("x"+self, -Velx);
        } else { setlocalvar("x"+self, Velx); }
      }
    }

    setlocalvar("T"+self, NULL()); //Clears variable
}

void targetL(float Vy, float dx, float dz, int Flip)
{// Targetting opponent before performing targetted leap attack
// Vy = y Velocity
// dx = x added distance
// dz = z added distance

    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if (dir == 0){ //Is entity facing left? 
      dx = -dx; //Reverse X direction to match facing
    }

    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    if( getlocalvar("T"+self) != NULL()){
      void target = getlocalvar("T"+self);
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");

      if(Flip == 1){
        if(Tx < x){
          changeentityproperty(self, "direction", 0);
        } else {
          changeentityproperty(self, "direction", 1);
        }
      }

      x = x+dx;
      z = z+dz;
      setlocalvar("x"+self, (Tx-x)/(22*Vy));
      setlocalvar("z"+self, (Tz-z)/(22*Vy));

    } else {
      setlocalvar("z"+self, 0);
      setlocalvar("x"+self, 0);
    }

    setlocalvar("T"+self, NULL()); //Clears variable
}


void targetTele()
{// Target opponent for teleport action

    void self = getlocalvar("self");
    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    if( getlocalvar("T"+self) != NULL()){
      void target = getlocalvar("T"+self);
      float Tx = getentityproperty(target, "x");
      float Ty = getentityproperty(target, "a");
      float Tz = getentityproperty(target, "z");
      setlocalvar("Tx"+self, Tx);
      setlocalvar("Ty"+self, Ty);
      setlocalvar("Tz"+self, Tz);
    }

    setlocalvar("T"+self, NULL()); //Clears variable
}

void Teletarget(float dx, float dy, float dz, int YFlag)
{// Teleport self right at target's position
// dx = x added distance
// dy = y added distance
// dz = z added distance
// YFlag = Flag to control if altitude is taken or not

    void self = getlocalvar("self");
    int Direction = getentityproperty(self, "direction");
    float Tx = getlocalvar("Tx"+self);
    float Ty;
    float Tz = getlocalvar("Tz"+self);
    void vSpawn;

    if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
    }
    if (YFlag == 1){ //Altitude is taken?                  
      Ty = getlocalvar("Ty"+self);
    } else { //Altitude is taken?                  
      Ty = 0;
    }

    if(Tx!= NULL() && Ty!= NULL() && Tz!= NULL()){
      changeentityproperty(self, "position", Tx+dx, Tz+dz, Ty+dy);
    }
}

void layer(int layer)
{// Установить слой врагу
    void self = getlocalvar("self");
    changeentityproperty(self, "setlayer", layer);
}

void suicide()
{ // Cуицид!!
    void self = getlocalvar("self");
    killentity(self);
}

void suicide2()
{
    void self = getlocalvar("self");

    damageentity(self, self, 1000, 0, openborconstant("ATK_NORMAL2"));
}

void killgun(int Num, int Flag)
{
    void self = getlocalvar("self");
    void Gun = getentityvar(self, Num);

    if(Gun!=NULL()){
      bindentity(Gun, NULL());
      if(Flag==1){
        damageentity(Gun, self, 1000, 0, openborconstant("ATK_NORMAL"));
      } else {
        killentity(Gun);
      }
    }
}

void givescore(int Add)
{// Дать игроку очки
    void P1 = getplayerproperty(0, "entity");
    void P2 = getplayerproperty(1, "entity");

    if(P1!=NULL()){
      int P1Score = getplayerproperty(0, "score");
      changeplayerproperty(0, "score", P1Score+Add);
    }

    if(P2!=NULL()){
      int P2Score = getplayerproperty(1, "score");
      changeplayerproperty(1, "score", P2Score+Add);
    }
}

void spawnGun(void Name, float dx, float dy, float dz, int Num)
{
   void self = getlocalvar("self");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, 0);
   setentityvar(self, Num, Spawn);
   bindentity(Spawn, self, dx, dz, dy, 0, 0); 
}

void spawnMover(void Name, float dx, float dy, float dz, int Num)
{
   void self = getlocalvar("self");
   int Aggro = getentityproperty(self,"aggression");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, 0);
   changeentityproperty(Spawn, "aggression", Aggro);
   setentityvar(self, Num, Spawn);
   bindentity(self, Spawn, dx, dz, dy, 0, 0);
}

void stop()
{// Остановить движение врагу!
    void self = getlocalvar("self");
    changeentityproperty(self, "velocity", 0, 0, 0);
}

void finisher2(void AniP, void Ani , int RxMin, int RxMax, int Rz, int Type, int Flag)
{

    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");
    void vEntity;
    int  iEntity;
    int  iType;
    int  iMax      = openborvariant("ent_max");

    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);
      iType   = getentityproperty(vEntity, "type");

      if (iType == openborconstant("TYPE_PLAYER")){
        float Tx = getentityproperty(vEntity, "x");
	float Tz = getentityproperty(vEntity, "z");
        int Anti = getentityproperty(vEntity, "antigrab");
        int Edir = getentityproperty(vEntity, "direction");
	void PAnim = getentityproperty(vEntity, "animationID");

        if(PAnim == openborconstant(AniP)){
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx >= RxMin && Disx <= RxMax && Disz <= Rz && dir == 1 )
      {
        if(Type == 2){
          if(((Flag == 1 && Edir == 0) || Flag == 0) && Anti < 10){
            dasher(0,0,0);
            setlocalvar("Target" + self, vEntity);
            performattack(self, openborconstant(Ani));
          }
        } else {
          if((Flag == 1 && Edir == 0) || Flag == 0){
            if(Type == 1){
              dasher(0,0,0);
              setlocalvar("Target" + self, vEntity);
            }
            performattack(self, openborconstant(Ani));
          }
        }
      } else if( Disx >= -RxMax && Disx <= -RxMin && Disz <= Rz && dir == 0)
      {
        if(Type == 2){
          if(((Flag == 1 && Edir == 1) || Flag == 0) && Anti < 10){
            dasher(0,0,0);
            setlocalvar("Target" + self, vEntity);
            performattack(self, openborconstant(Ani));
          }
        } else {
          if((Flag == 1 && Edir == 1) || Flag == 0){
            if(Type == 1){
              dasher(0,0,0);
              setlocalvar("Target" + self, vEntity);
            }
            performattack(self, openborconstant(Ani));
          }
        }
      }
        }
      }
    }
}

void shootT(void Shot, float dx, float dy, float dz)
{
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float Vx = getlocalvar("x"+self);
   float Vz = getlocalvar("z"+self);
   void vShot;

   if (Direction == 0){              
      dx = -dx;
   }

   vShot = projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);

   if( Vx!=NULL() && Vz!=NULL() ){
     changeentityproperty(vShot, "velocity", Vx, Vz);
     if (Vx < 0 && Direction == 1){
       changeentityproperty(vShot, "direction", 0);
     } else if(Vx > 0 && Direction == 0){
       changeentityproperty(vShot, "direction", 1);
     }
     if ( Vx < 0 ){
       Vx = -Vx;
     }
     changeentityproperty(vShot, "speed", Vx);
   }
}

void TossThrow (void Bomb, float dx, float dy, float Vx, float Vy, float Vz)
{ // Бросок предмета
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   void vShot;

   if (Direction == 0){ //Объект повернут влево?                  
      Vx = -Vx; //Реверс Vx директория к лицу
   }

   vShot = spawn01(Bomb, dx, dy, 0);
   tossentity(vShot, Vy, Vx, Vz, 0);
   return vShot;
}

void SpawnRandEnt(void vName1, void vName2, void vName3, void vName4, int vX, int vY, int vZ )
// Spawn разных сущностей на разном месте
// 12/08/2017 - Отредактировал - Чернобаев Александр - MKLIUKANG1
{
// int Xr = rand()%vx; // Random X pos
// int Yr = rand()%vy; // Random Y pos
// int Zr = rand()%vz; // Random Z pos

int Sr = rand()%-2+2;

if(Sr == 0){
	spawn01(vName1, vX, vY, vZ);
	}
	
else if(Sr == 1){
	spawn01(vName2, vX, vY, vZ);
	}
	
else if(Sr == 2){
	spawn01(vName3, vX, vY, vZ);
	}
	
else {
	spawn01(vName4, vX, vY, vZ);
	 }
	 
}

void	DeControl(int P, int Flag)
{// 			Активирует или деактивирует контроль для определенного игрока.
 // P: 			индекс игрока, начинающийся с 0.
 // Flag:		флаг управления.
 // Decontrol 	0 1, чтобы отключить управление над игроком 1
 // DeControl 	1 1, чтобы отключить управление над игроком 2
 // De Contol 	0 0, чтобы включить управление для игрока 1
  // De Contol 	1 0, чтобы включить управление для игрока 2
 // Скрипт от Bloodbane
 
	int Player = getplayerproperty(P, "entity");
	
	if (Player != NULL()){
	changeentityproperty (Player, "noaicontrol", Flag);
    }
}

void shooterW(void Shot, float dx, float dy, float V, int Angle)
{
    int WP = getglobalvar("WP");
    void Spawn;

    Spawn = shooterAngle(Shot, dx, dy, V, Angle);
    changeentityproperty(Spawn, "offense", openborconstant("ATK_NORMAL"), WP);
}

void shooterAngle(void Shot, float dx, float dy, float V, int Angle)
{
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int Vx = V*cos(Angle);
   int Vy = 2*V*sin(Angle);
   void vShot;

   vShot = shooter(Shot, dx, dy, Vx, Vy, 1);

   if (Direction == 1){
     Angle = 360-Angle;
   }

   if(Angle >= 360){
     Angle = Angle-360;
   } else if(Angle < 0){
     Angle = Angle+360;
   }

   changedrawmethod(vShot, "rotate", Angle);
   return vShot;
}

void shooter(void Shot, float dx, float dy, float Vx, float Vy, int Flag)
{
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   void vShot;

   if (Direction == 0){            
      Vx = -Vx; 
   }

   vShot = spawn01(Shot, dx, dy, 0);
   changeentityproperty(vShot, "velocity", Vx, 0, Vy);

   if(Flag == 1){
     changedrawmethod(vShot, "reset", 1);
   }

   return vShot;
}

void nomoveidle()
{
    void self = getlocalvar("self");
    int iPIndex = getentityproperty(self,"playerindex");
    void iRKeyL = playerkeys(iPIndex, 0, "moveleft");
    void iRKeyR = playerkeys(iPIndex, 0, "moveright");

    if (!iRKeyL&&!iRKeyR){
      stop();
      setidle(self, openborconstant("ANI_IDLE"));
    }
}

void keyjump(int Height)
{
    void self = getlocalvar("self");
    int iPIndex = getentityproperty(self,"playerindex");
    float xdir = 0;

    if (playerkeys(iPIndex, 0, "jump")){
      if (playerkeys(iPIndex, 0, "moveleft")){
	xdir = -1;
      } else if(playerkeys(iPIndex, 0, "moveright")){
	xdir = 1;
      }
      tossentity(self, Height, xdir, 0);

      changeentityproperty(self, "animation", openborconstant("ANI_JUMP"));
      changeentityproperty(self, "aiflag", "idling", 0);
      changeentityproperty(self, "aiflag", "jumping", 1);
      changeentityproperty(self, "takeaction", "common_jump");
    }
}

void landidle()
{
    void self = getlocalvar("self");
    int y = getentityproperty(self, "a");
    int b = getentityproperty(self, "base");

    if (y == b){
      stop();
      setidle(self, openborconstant("ANI_IDLE"));
    }
}

void mpcost(int Cost)
{
    void self = getlocalvar("self");
    int MP = getentityproperty(self,"mp");

    changeentityproperty(self, "mp", MP-Cost);
}
