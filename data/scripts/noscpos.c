void main()
{
    void self = getlocalvar("self");
    int x = getentityproperty(self,"x");
    int XPos = openborvariant("xpos");

    changeentityproperty(self, "position", x - XPos);
}
