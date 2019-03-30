void spawnEntity(void vName, float fX, float fY, float fZ,int map,int bind,int pos)
{
	void self = getlocalvar("self");
	void vSpawn=spawnEn(vName);
	if (getentityproperty(self,"type")==openborconstant("type_player"))
	{
		changeentityproperty(vSpawn,"candamage","type_enemy","type_obstacle");
	}
	if (getentityproperty(self,"type")==openborconstant("type_enemy"))
	{
		changeentityproperty(vSpawn,"candamage","type_player","type_npc");
	}
	changeentityproperty(vSpawn,"parent",self);
	if (bind)
	{	
		bindentity(vSpawn,self,fX,fZ,fY,1,0);
	}else{
		int  iDirection = getentityproperty(self, "direction");
		if (!pos){
			if (iDirection == 0){ //facing left                  
				fX = -fX;
			}
			fX = fX + getentityproperty(self, "x");
			fY = fY + getentityproperty(self, "a");
			fZ = fZ + getentityproperty(self, "z");
		}else{
			iDirection=1;
			fX=fX+openborvariant("xpos");
			fY=openborvariant("ypos") - getentityproperty(self,"z");
		}
		changeentityproperty(vSpawn, "direction", iDirection);
		changeentityproperty(vSpawn, "position", fX, fZ, fY);
	}
	if (map>0){
		changeentityproperty(vSpawn, "map", map);
	}
	return vSpawn;
}

void spawn01(void vName, float fX, float fY, float fZ)
{
	return spawnEntity(vName, fX, fY, fZ,0,0,0); //Spawn in entity.
}
void spawn02(void vName)
{
	return spawnEntity(vName, 0, 0, 0,0,0,1); //Spawn in entity.
}

void spawn_z(void vName)
{
	void self = getlocalvar("self");
	void target=findtarget(self);
	void vSpawn;
	if(target!=NULL())
	{
		float Tx = getentityproperty(target, "x");
		float Tz = getentityproperty(target, "z");
		clearspawnentry();
		setspawnentry("name", vName);
		vSpawn=spawn();

		if (getentityproperty(self,"type")==openborconstant("type_player"))
		{
			changeentityproperty(vSpawn,"candamage","type_enemy","type_obstacle");
		}
		if (getentityproperty(self,"type")==openborconstant("type_enemy"))
		{
			changeentityproperty(vSpawn,"candamage","type_player","type_npc");
		}

		changeentityproperty(vSpawn, "position", Tx, Tz, 0);
	}
	return vSpawn;
}

void spawnEn(void vName)
{
	clearspawnentry();
	setspawnentry("name", vName);
	void vSpawn=spawn();
	return vSpawn;
}
