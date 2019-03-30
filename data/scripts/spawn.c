#define MAX_ALTITUDE 5000
#define MAX_PLAYERS openborvariant("maxplayers")

void main() {
    void self = getlocalvar("self");

    set_inspawning(self,15); // must be first func!!
    set_coords_predeath(self);
    set_coords(self,5000);
}

int set_coords(void player, float max_alt) {
    if ( getentityproperty(player, "animationid") == openborconstant("ANI_RESPAWN") ) {
        float x,z,a,base;
        int p = getentityproperty(player, "playerindex"); // non puoi ricavarti il player con getentityproperty(getplayerproperty(p, "entity")) poichè non esiste ancora
        int t;

        x = getglobalvar("p"+(p+1)+"respawn_x");
        z = getglobalvar("p"+(p+1)+"respawn_z");
        a = getglobalvar("p"+(p+1)+"respawn_a");
        base = getglobalvar("p"+(p+1)+"respawn_base");

        if ( get_ready_players_count() > 1 ) {
            if ( check_incam_pos(x,z) == 1 ) { // siamo nel riquadro giusto?
                // se sono nulle allora non è mai stato nel livello il personaggio. Verrà eseguita l'animazione RESPAWN
                if ( x != NULL() && z != NULL() && a != NULL() && a < max_alt ) {
                    //changeentityproperty(player, "subject_to_wall", 0);
                    //changeentityproperty(player, "subject_to_platform", 0);
                    changeentityproperty(player, "position", x, z, a);
                } else {
                    void last_player = getglobalvar("last_player_spawned");
                    int p = getentityproperty(last_player, "playerindex");
                    int distance = getlocalvar("distance");
                    int result;

                    //if ( !getentityproperty(last_player,"exists") || getentityproperty(last_player,"type") != openborconstant("type_player") ) {
                        last_player = generate_last_player_spawned(player,1);
                    //}

                    if (distance == NULL()) distance = 15;
                    result = check_respawn(player,distance);
                    if ( result < 1 ) set_latest_safe_coords(player);
                    setlocalvar("respawn", 1);
                }
            } else {
                void last_player = getglobalvar("last_player_spawned");
                int p = getentityproperty(last_player, "playerindex");
                int distance = getlocalvar("distance");
                int result;

                //if ( !getentityproperty(last_player,"exists") || getentityproperty(last_player,"type") != openborconstant("type_player") ) {
                    last_player = generate_last_player_spawned(player,1);
                //}

                if (distance == NULL()) distance = 15;
                result = check_respawn(player,distance);
                if ( result < 1 ) set_latest_safe_coords(player);
                setlocalvar("respawn", 1);
            } // fine if incam
        } else { // la funzione incam() ha senso con più di un giocatore in gara
                if ( x != NULL() && z != NULL() && a != NULL() && a < max_alt ) {
                    changeentityproperty(player, "position", x, z, a);
                } else {
                    void last_player = getglobalvar("last_player_spawned");
                    int p = getentityproperty(last_player, "playerindex");
                    int distance = getlocalvar("distance");
                    int result;

                    //if ( !getentityproperty(last_player,"exists") || getentityproperty(last_player,"type") != openborconstant("type_player") ) {
                        last_player = generate_last_player_spawned(player,1);
                    //}

                    if (distance == NULL()) distance = 15;
                    result = check_respawn(player,distance);
                    if ( result < 1 ) set_latest_safe_coords(player);
                    setlocalvar("respawn", 1);
                }
        } // fine if ready_players_count()

        // ##### IMPORTANTE: Facciamo eseguire questo script per tutta la durata del respawn!! Perchè al primo frame potrebbero accadere errori!!
    }
}

int get_ready_players_count() {
    int p, count = 0;

    for (p = 0; p < MAX_PLAYERS; ++p) {
        void player = getplayerproperty(p, "entity");

        if ( getentityproperty(player,"exists") ) {
            int anim_id = getentityproperty(player, "animationid");

            if ( anim_id != openborconstant("ANI_SPAWN") && anim_id != openborconstant("ANI_RESPAWN") ) {
                ++count;
            }
        }
    } // fine for

    return count;
}

void set_latest_safe_coords(void player) {
    float xmax = NULL();
    int p;
    float xp,zp,ap,basep,x,z,a;
    int pindex = getentityproperty(player, "playerindex");

    for (p = 0; p < MAX_PLAYERS; ++p) {
        int max_player = getplayerproperty(p, "entity");

        //if ( !getentityproperty(max_player, "exists") ) continue;

        xp = getglobalvar("p"+(p+1)+"respawn_x");
        zp = getglobalvar("p"+(p+1)+"respawn_z");
        ap = getglobalvar("p"+(p+1)+"respawn_a");
        basep = getglobalvar("p"+(p+1)+"respawn_base");

        if ( xmax == NULL() || xp > xmax ) {
            if ( xp != NULL() && zp != NULL() && ap != NULL() && check_incam_pos(xp,zp) == 1 ) {
                xmax = xp;
                setglobalvar("p"+(pindex+1)+"respawn_x",xp);
                setglobalvar("p"+(pindex+1)+"respawn_z",zp);
                setglobalvar("p"+(pindex+1)+"respawn_a",ap);
                setglobalvar("p"+(pindex+1)+"respawn_base",basep);
            }
        } // fine if xmax
    } // fine for

    if ( x != NULL() && z != NULL() && a != NULL() ) {
        changeentityproperty(player, "position", x, z, a);
    }
}

// if flag on, search last player spawned but not == self
void generate_last_player_spawned(void self, int self_flag) {
    int p;
    float last_player = NULL();

    for (p = 0; p < MAX_PLAYERS; ++p) {
        int player = getplayerproperty(p, "entity");
        int time = NULL(), last_time = NULL();

        if ( !getentityproperty(player, "exists") ) continue;
        if ( getglobalvar("p"+(p+1)+"spawning") == 1 ) continue; // sta spawnando ora
        if ( self_flag > 1 && self == player ) continue;

        time = getglobalvar("p"+(p+1)+"spawn_time");
        if ( last_time == NULL() || time > last_time ) {
            last_player = player;
            last_time = time;
        }
    } // fine for

    setglobalvar("last_player_spawned", last_player);

    return last_player;
}

void set_inspawning(void player, int respawn_distance) {
    int anim_id = getentityproperty(player, "animationid");

    if ( anim_id == openborconstant("ANI_RESPAWN") || anim_id == openborconstant("ANI_SPAWN") ) {
        int p = getentityproperty(player, "playerindex");

        if ( respawn_distance != getlocalvar("distance") ) setlocalvar("distance", respawn_distance);
        if ( getglobalvar("p"+(p+1)+"spawning") != 1 ) setglobalvar("p"+(p+1)+"spawning", 1);
    } else {
        int p = getentityproperty(player, "playerindex");

        if ( getglobalvar("p"+(p+1)+"spawning") == 1 ) {
                setglobalvar("last_player_spawned", player);
                setglobalvar("p"+(p+1)+"spawn_time", openborvariant("elapsed_time"));
                if ( getlocalvar("respawn") != NULL() ) setlocalvar("respawn", NULL());
                setglobalvar("p"+(p+1)+"spawning", 0);
        }
    }

}

int check_incam_pos(float x, float z) {
    float scr_posx = openborvariant("xpos");
    int hres = openborvariant("hresolution");
    float zmin_distance = get_zmin_distance();
    float zmax_distance = get_zmax_distance();
    float threshold = 5;

    if ( x == NULL() || z == NULL() ) return 0;
    if ( x < scr_posx+threshold || x > scr_posx+hres-threshold ) return 0;
    if ( z < zmin_distance+threshold || z > zmax_distance-threshold ) return 0;

    return 1;
}

int set_coords_predeath(void player, float max_alt) {
    int frames = 2;
    int refresh_time = openborvariant("elapsed_time")%frames;
    int anim_id = getentityproperty(player, "animationid");
    /*if (openborvariant("in_level")) {
            int mem_frames = openborvariant("game_speed");
    }*/

    if ( refresh_time == 0 && anim_id != openborconstant("ANI_SPAWN") && anim_id != openborconstant("ANI_RESPAWN") ) {
        float x = getentityproperty(player, "x");
        float z = getentityproperty(player, "z");
        float a = getentityproperty(player, "a");
        float base = getentityproperty(player, "base");
        int p = getentityproperty(player, "playerindex");

        if ( ( anim_id == openborconstant("ANI_IDLE") || anim_id == openborconstant("ANI_RUN") || anim_id == openborconstant("ANI_WALK") || anim_id == openborconstant("ANI_LAND")
            || anim_id == openborconstant("ANI_GET") || anim_id == openborconstant("ANI_BLOCK") || anim_id == openborconstant("ANI_UP") || anim_id == openborconstant("ANI_DOWN")
            || anim_id == openborconstant("ANI_JUMPLAND") ) && checkhole(x,z) == 0 && (a == base) ) {

            //drawstring( 10,200,0,"Storing Coords...");
            setglobalvar("p"+(p+1)+"respawn_x", x);
            setglobalvar("p"+(p+1)+"respawn_z", z);
            setglobalvar("p"+(p+1)+"respawn_a", a);
            setglobalvar("p"+(p+1)+"respawn_base", base);

            // Memorizziamo l'altitudine così da confrontarla con la prossima al prossimo frame. In caso si deve memorizzare la posizione sopra una piattaforma.
            // Infatti se stesse saltando o cadendo l'altitudine non sarebbe mai uguale da un frame all'altro...
            //setlocalvar("a_coord", a);
        }
    }
}

// Sistemiamo il personaggio dopo il respawn ne caso è dentro una platform (lo script può essere eseguito solo ora e non onspawn event)
// 1 ha esito positivo, 0 non esiste l'ultimo player spawned o non è nel quadro, -1 ultimo giocatore spawnato è se stesso, 2 non viene eseguito
int check_respawn(void player, float threshold) {
    if ( getentityproperty(player, "animationid") == openborconstant("ANI_RESPAWN") && getlocalvar("respawn") == NULL() ) { // && getentityproperty(player, "animpos") > 0
        void last_player = getglobalvar("last_player_spawned");

            //drawstring( 20,160,0,"Siamo qui!" );
            if ( getglobalvar("last_player_spawned") == player ) {
                    return -1; // Questa funzione ha senso rispetto ad altri giocatori e non a se stessi!! Altrimenti usare le p#respawn_X
            }

            if ( !getentityproperty(last_player,"exists") || getentityproperty(last_player,"type") != openborconstant("type_player") || last_player == NULL() ) {
                return 0;
            } else {
                int p = getentityproperty(last_player, "playerindex");
                float x = getglobalvar("p"+(p+1)+"respawn_x");
                float z = getglobalvar("p"+(p+1)+"respawn_z");
                float a = getglobalvar("p"+(p+1)+"respawn_a");
                float base = getglobalvar("p"+(p+1)+"respawn_base");
                int i;
                float t_alt = MAX_ALTITUDE;
                float x2, z2;
                float wall, platform_a;
                void platform;

                    if ( check_incam_pos(x,z) == 0 ) {
                        return 0;
                    }

                    // Respawniamo un valore threshold di px in avanti/dietro/giù/su rispetto al giocatore già in gara
                    for ( i = 0; i <= threshold; ++i ) { // <= così può assumere valore 0!
                            x2 = x-(threshold-i); z2 = z+(threshold-i);
                            wall = checkwall(x2,z2); platform = checkplatform(x2,z2,t_alt);
                            if ( platform != NULL() ) platform_a = getentityproperty(platform, "a");
                            if ( (wall <= 0 || (wall > 0 && wall == a)) && (platform == NULL() || (platform != NULL() && platform_a == a)) && checkhole(x2,z2) == 0 ) break; // vedi se stai sopra un muro o una piattaforma

                            x2 = x-(threshold-i); z2 = z-(threshold-i);
                            wall = checkwall(x2,z2); platform = checkplatform(x2,z2,t_alt);
                            if ( platform != NULL() ) platform_a = getentityproperty(platform, "a");
                            if ( (wall <= 0 || (wall > 0 && wall == a)) && (platform == NULL() || (platform != NULL() && platform_a == a)) && checkhole(x2,z2) == 0 ) break;

                            x2 = x+(threshold-i); z2 = z+(threshold-i);
                            wall = checkwall(x2,z2); platform = checkplatform(x2,z2,t_alt);
                            if ( platform != NULL() ) platform_a = getentityproperty(platform, "a");
                            if ( (wall <= 0 || (wall > 0 && wall == a)) && (platform == NULL() || (platform != NULL() && platform_a == a)) && checkhole(x2,z2) == 0 ) break;

                            x2 = x+(threshold-i); z2 = z-(threshold-i);
                            wall = checkwall(x2,z2); platform = checkplatform(x2,z2,t_alt);
                            if ( platform != NULL() ) platform_a = getentityproperty(platform, "a");
                            if ( (wall <= 0 || (wall > 0 && wall == a)) && (platform == NULL() || (platform != NULL() && platform_a == a)) && checkhole(x2,z2) == 0 ) break;

                            x2 = x; z2 = z+(threshold-i);
                            wall = checkwall(x2,z2); platform = checkplatform(x2,z2,t_alt);
                            if ( platform != NULL() ) platform_a = getentityproperty(platform, "a");
                            if ( (wall <= 0 || (wall > 0 && wall == a)) && (platform == NULL() || (platform != NULL() && platform_a == a)) && checkhole(x2,z2) == 0 ) break;

                            x2 = x; z2 = z-(threshold-i);
                            wall = checkwall(x2,z2); platform = checkplatform(x2,z2,t_alt);
                            if ( platform != NULL() ) platform_a = getentityproperty(platform, "a");
                            if ( (wall <= 0 || (wall > 0 && wall == a)) && (platform == NULL() || (platform != NULL() && platform_a == a)) && checkhole(x2,z2) == 0 ) break;

                            x2 = x; z2 = z+(threshold-i);
                            wall = checkwall(x2,z2); platform = checkplatform(x2,z2,t_alt);
                            if ( platform != NULL() ) platform_a = getentityproperty(platform, "a");
                            if ( (wall <= 0 || (wall > 0 && wall == a)) && (platform == NULL() || (platform != NULL() && platform_a == a)) && checkhole(x2,z2) == 0 ) break;

                            x2 = x; z2 = z-(threshold-i);
                            wall = checkwall(x2,z2); platform = checkplatform(x2,z2,t_alt);
                            if ( platform != NULL() ) platform_a = getentityproperty(platform, "a");
                            if ( (wall <= 0 || (wall > 0 && wall == a)) && (platform == NULL() || (platform != NULL() && platform_a == a)) && checkhole(x2,z2) == 0 ) break;

                            x2 = x-(threshold-i); z2 = z;
                            wall = checkwall(x2,z2); platform = checkplatform(x2,z2,t_alt);
                            if ( platform != NULL() ) platform_a = getentityproperty(platform, "a");
                            if ( (wall <= 0 || (wall > 0 && wall == a)) && (platform == NULL() || (platform != NULL() && platform_a == a)) && checkhole(x2,z2) == 0 ) break;

                            x2 = x-(threshold-i); z2 = z;
                            wall = checkwall(x2,z2); platform = checkplatform(x2,z2,t_alt);
                            if ( platform != NULL() ) platform_a = getentityproperty(platform, "a");
                            if ( (wall <= 0 || (wall > 0 && wall == a)) && (platform == NULL() || (platform != NULL() && platform_a == a)) && checkhole(x2,z2) == 0 ) break;

                            x2 = x+(threshold-i); z2 = z;
                            wall = checkwall(x2,z2); platform = checkplatform(x2,z2,t_alt);
                            if ( platform != NULL() ) platform_a = getentityproperty(platform, "a");
                            if ( (wall <= 0 || (wall > 0 && wall == a)) && (platform == NULL() || (platform != NULL() && platform_a == a)) && checkhole(x2,z2) == 0 ) break;

                            x2 = x+(threshold-i); z2 = z;
                            wall = checkwall(x2,z2); platform = checkplatform(x2,z2,t_alt);
                            if ( platform != NULL() ) platform_a = getentityproperty(platform, "a");
                            if ( (wall <= 0 || (wall > 0 && wall == a)) && (platform == NULL() || (platform != NULL() && platform_a == a)) && checkhole(x2,z2) == 0 ) break;
                    } // fine for

                changeentityproperty(player, "position", x2, z2, a);

                //setglobalvar("last_player_spawned", player); // Impostiamo l'ultimo giocatore spawnato!
                // Lo impostiamo tra le animazioni con @cmd...
                setlocalvar("respawn", 1);
                return 1;
            } // fine if last_player exists
    } else {
        return 2;
    }
}

int checkplatform(float distx, float distz, float altitude) {
    if ( checkplatformbelow(distx,distz,altitude) == checkplatformbelow(0,0,0) ) return NULL();
    else return checkplatformbelow(distx,distz,altitude);
}

float get_zmin_distance() {
    float scr_posy = openborvariant("ypos");
    int zmin_threshold = 20;
    float zmin_bound = scr_posy+zmin_threshold;

    return zmin_bound;
}

float get_zmax_distance() {
    float scr_posy = openborvariant("ypos");
    int vres = openborvariant("vresolution");
    int zmax_threshold = 20;
    float zmax_bound = scr_posy+vres+zmax_threshold;

    return zmax_bound;
}
