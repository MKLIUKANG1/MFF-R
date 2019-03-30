void lock()
{
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);
	if(!target)
	{
		target = getentityproperty(self, "grabbing");
		if (!target){
			target = getentityproperty(self, "opponent");
		}
	}
	if(target){
		if(!getentityproperty(target,"dead")&&
			(getentityproperty(target,"type")==openborconstant("TYPE_ENEMY")||
			getentityproperty(target,"type")==openborconstant("TYPE_PLAYER"))
			)
		{
			setlocalvar("Target" + self, target);
			changeentityproperty(target,"stalltime",openborvariant("elapsed_time")+10000);
			performattack(target,openborconstant("ANI_FALL7"));
		}else{
			setlocalvar("Target" + self, NULL());
			if(self){
				changeAni("ANI_IDLE");
				setidle(self);
			}
		}
	}
}
void position(int Frame, float dx, float dy, float dz, int face)
{
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);
	if(target!=NULL())
	{
		updateframe(target, Frame);
		bindentity(target, self, dx, dz, dy, face, 0);
	}
}
void clearSlam()
{
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);
	void x,zself,x1,xself,offset,wall;
	void base=getentityproperty(self,"base");
	int i;
	if(target!=NULL())
	{
		bindentity(target, NULL());
		setlocalvar("Target"+self,NULL());
		x=getentityproperty(target,"x");
		xself=getentityproperty(self,"x");
		zself=getentityproperty(self,"z");
		if (xself>x){
			offset=2;
		}else{
			offset=-2;
		}
		for (i=0;i<200;i++)
		{
			wall=checkwall(x,zself);
			if (wall<=base){
				changeentityproperty(target,"position",x,zself);
				return;
			}
			x+=offset;
		}
	}
}

void finish(int Damage, int x, int y, int z, int Face)
{ // Damage as slam or throw finisher
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);
	int SDir = getentityproperty(target,"direction");
	int MDir;

	if(Face==0){ // Same facing?
		MDir = SDir;
	}

	if(Face==1){ // Opposite facing?
		if(SDir==0){ // Facing left?
			MDir = 1;
		} else{ 
			MDir = 0;
		}
	}

	if(target==NULL())
	{
		setidle(self);//Target lost.Normally it's impossible!
	}else{
		int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
		if(dir==0){ // Facing left?
			x = -x;
		}
		damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL")); 
		tossentity(target, y, x, z); // Toss opponent ;)
		changeentityproperty(target, "direction", MDir);
		//changeentityproperty(target, "health", 100);
	}
}


void throw(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as throw finisher
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){ // Same facing?
       MDir = SDir;
   }

   if(Face==1){ // Opposite facing?

     if(SDir==0){ // Facing left?
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
     int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
     if(dir==0){ // Facing left?
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL")); // 1st throw type
     }

     if(Type==2)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL9")); // 2nd throw type
     }

     if(Type==3)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL2")); // 3rd throw type, enemies can autoland here
     }

     changeentityproperty(target, "attacking", 1);
     changeentityproperty(target, "damage_on_landing", Damage);
     changeentityproperty(target, "projectile", 1);
     changeentityproperty(target, "direction", MDir);
     tossentity(target, y, x, z); // Toss opponent ;)
   }
}

void hurt(int damage)
{ 
	hurt2(damage,0);
}

void hurt2(int damage,int is_live)
{
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);
	
	float x,z;
	x=getentityproperty(self,"x");
	z=getentityproperty(self,"z");
	if (checkhole(x,z)){
		clearSlam();
		return;
	}
	x=getentityproperty(target,"x");
	z=getentityproperty(target,"z");
	if (checkhole(x,z)){
		clearSlam();
		return;
	}else{}
	void at = getentityproperty(self, "offense",openborconstant("ATK_NORMAL"));
	void df= getentityproperty(target, "defense", openborconstant("ATK_NORMAL"), "factor");
	damage*=at*df;
	if(target!=NULL()){
		int damage2;
		int THealth = getentityproperty(target,"health");
		int TAniPos = getentityproperty(target,"animpos");
		if (is_live==1){
			if(THealth > damage){
				damage2=damage;
			}else{
				damage2 = THealth - 1;
			}
		}else{
			damage2=damage;
		}
		damageentity(target, self, damage2, 1, openborconstant("ATK_NORMAL7"));
		updateframe(target, TAniPos);
	}
}
void slamInt()
{
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);

	if(target!=NULL())
	{
		damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL"));
		clearSlam();
	}
}
