void () SUB_CalcAngleMoveDone;
void () SUB_Null;
void () SUB_UseTargets;
void () SUB_Remove;

void (entity ent, vector destangle, float tspeed, void() func) SUB_CalcAngleMoveEnt;
void (vector destangle, float tspeed, void() func) SUB_CalcAngleMove;
void (entity ent, vector tdest, float tspeed, void() func) SUB_CalcMoveEnt;
void (vector tdest, float tspeed, void() func) SUB_CalcMove;
void () SUB_CalcMoveDone;


string (float tno) GetTeamName;


void (entity targ, entity inflictor, entity attacker, float damage) T_Damage;
float (entity e, float healamount, float ignore) T_Heal;
float (entity targ, entity inflictor) CanDamage;
.float playerclass;
.float nextpc;
.float last_impulse;
.float armorclass;
.float tf_items;
.float tf_items_flags;
.float no_grenades_1;
.float no_grenades_2;
.float tp_grenades_1;
.float tp_grenades_2;
.float got_aliases;
.float cheat_check;
.float is_removed;
.float is_undercover;
.float is_building;
.float is_detpacking;
.float is_feigning;
.float is_unabletospy;
.float has_disconnected;
.float has_dispenser;
.float has_sentry;
.float tfstate;
.entity linked_list;
.entity observer_list;
.float maxammo_shells;
.float maxammo_nails;
.float maxammo_cells;
.float maxammo_rockets;
.float items_allowed;
.float armor_allowed;
.float maxarmor;
.float maxfbspeed;
.float maxstrafespeed;
.float weaponmode;
.float motd;
.float current_menu;
.float menu_count;
.float menu_displaytime;
float toggleflags;
float respawn_delay_time;
float number_of_teams;
float illegalclasses    = 0;
float illegalclasses1;
float illegalclasses2;
float illegalclasses3;
float illegalclasses4;
float civilianteams;
float team1col;
float team2col;
float team3col;
float team4col;
float team1score;
float team2score;
float team3score;
float team4score;
float team1lives;
float team2lives;
float team3lives;
float team4lives;
float team1maxplayers;
float team2maxplayers;
float team3maxplayers;
float team4maxplayers;
float team1advantage;
float team2advantage;
float team3advantage;
float team4advantage;
.float team_no;
.float lives;
.float infection_team_no;
float CTF_Map;
float coop    = 0;
float rj;
float TF_FLARE_LIT    = 0;
float TF_FLARE_OFF    = 1;
.entity building;
.float building_wait;
.entity real_owner;
.float real_frags;
.float respawn_time;
.float suicide_time;
.float weapons_carried;
.float current_weapon;
.float ammo_medikit;
.float maxammo_medikit;
.float ammo_detpack;
.float maxammo_detpack;
.float reload_shotgun;
.float reload_super_shotgun;
.float reload_grenade_launcher;
.float reload_rocket_launcher;
.float heat;
.float immune_to_check;
.float last_saveme_sound;
.float goal_no;
.float group_no;
.float goal_state;
.float owned_by;
.float goal_activation;
.float goal_effects;
.float goal_result;
.float goal_group;
.float else_goal;
.float if_goal_is_active;
.float if_goal_is_inactive;
.float if_goal_is_removed;
.float if_group_is_active;
.float if_group_is_inactive;
.float if_group_is_removed;
.float activate_goal_no;
.float inactivate_goal_no;
.float remove_goal_no;
.float restore_goal_no;
.float activate_group_no;
.float inactivate_group_no;
.float remove_group_no;
.float restore_group_no;
.float has_item_from_group;
.float remove_item_group;
.float return_item_no;
.float if_item_has_moved;
.float if_item_hasnt_moved;
.float remove_spawnpoint;
.float restore_spawnpoint;
.float remove_spawngroup;
.float restore_spawngroup;
.float display_item_status1;
.float display_item_status2;
.float display_item_status3;
.float display_item_status4;
.string team_str_home;
.string team_str_moved;
.string team_str_carried;
.string non_team_str_home;
.string non_team_str_moved;
.string non_team_str_carried;
.float ex_skill_min;
.float ex_skill_max;
.float increase_team1;
.float increase_team2;
.float increase_team3;
.float increase_team4;
.string broadcast;
.string team_broadcast;
.string non_team_broadcast;
.string owners_team_broadcast;
.string netname_broadcast;
.string netname_team_broadcast;
.string netname_non_team_broadcast;
.string netname_owners_team_broadcast;
.string team_drop;
.string non_team_drop;
.string netname_team_drop;
.string netname_non_team_drop;
string team_menu_string;
.float all_active;
.float item_list;
float item_list_bit;
.float delay_time;
.float dont_do_triggerwork;
.float g_a;
.float g_e;
.string t_s_h;
.string t_s_m;
.string t_s_c;
.string n_s_h;
.string n_s_m;
.string n_s_c;
.string b_b;
.string b_t;
.string b_n;
.string b_o;
.string n_b;
.string n_t;
.string n_n;
.string n_o;
.string d_t;
.string d_n;
.string d_n_t;
.string d_n_n;
float num_world_flames;
.float numflames;
.string flame_id;
float num_world_pipebombs;
float num_team_pipebombs_1;
float num_team_pipebombs_2;
float num_team_pipebombs_3;
float num_team_pipebombs_4;
float num_world_ammoboxes;
float num_team_ammoboxes_1;
float num_team_ammoboxes_2;
float num_team_ammoboxes_3;
float num_team_ammoboxes_4;
.float undercover_team;
.float undercover_skin;
.string undercover_name;
float spy_off;
float invis_only;
float allow_hook;
.float hook_out;
float live_camera;
.float camdist;
.vector camangle;
.entity camera_list;
float already_chosen_map;
.entity hook;
.float on_hook;
.float fire_held_down;
.vector head_shot_vector;
.float leg_damage;
.float cheat_level;
.float FlashTime;
.float StatusRefreshTime;
.float StatusBarSize;
.float StatusBarRes;
float deathmsg;
float BOT_IDLE    = 1;
float BOT_FIGHTING    = 2;
float BOT_MOVING    = 4;
float BOT_DEFEND    = 8;
float BOT_RESUPPLYING    = 16;
float BOT_AVOIDING_HAZARD    = 32;
float BOT_AI_LEAD    = 2;
float BOT_AI_FOLLOW    = 3;
float BOT_AI_REFUEL    = 4;
float BOT_AI_GRAPPLE    = 5;
float BOT_AI_FLEE    = 6;
float BOT_AI_BLAST    = 7;
float BOT_AI_STEALTH    = 8;
float BOT_AI_FLAGRUN    = 9;
float BOT_AI_SCOUT    = 10;
float BOT_IMPULSE    = 200;
float FALSE    = 0;
float TRUE    = 1;
float DAMAGE_NO    = 0;
float MOVETYPE_NONE    = 0;
float MOVETYPE_WALK    = 3;
float MOVETYPE_STEP    = 4;
float MOVETYPE_FLY    = 5;
float MOVETYPE_TOSS    = 6;
float MOVETYPE_NOCLIP    = 8;
float MOVETYPE_BOUNCE    = 10;
float SOLID_NOT    = 0;
float SOLID_TRIGGER    = 1;
float SOLID_BSP    = 4;
float MSG_BROADCAST    = 0;
float MSG_ONE    = 1;
float MSG_ALL    = 2;
float FL_MONSTER    = 32;
float FL_ITEM    = 256;
float FL_ONGROUND    = 512;
float FL_PARTIALGROUND    = 1024;
float FL_WATERJUMP    = 2048;
float IT_INVISIBILITY    = 524288;
float CONTENT_EMPTY    = -1;
float CONTENT_WATER    = -3;
float CONTENT_LAVA    = -5;
vector VEC_HULL_MIN    = '-16 -16 -24';
vector VEC_HULL_MAX    = '16 16 32';
float MSG_MULTICAST    = 4;
.float ishuman;
.float tfrags;
.float fClientNo;
.float fShirt;
.float fPants;
.float fEnterTime;
.float fUserID;
.float keys;
.float action;
.float position;
.float obs_time;
.float avoidKeys;
.float checkMovementTime;
.float distanceToWaypoint;
.vector botDirection;
.vector pipeLocation;
.float f_sound;
.float missile_speed;
.float botskill;
.float switch_wallhug;
.entity phys_obj;
.vector b_angle;
.vector mouse_emu;
.vector movevect;
.vector punchangle;
.float nextimpulse;
.float should_stand;
.float oldAction;
.vector waypoint1;
.vector waypoint2;
.vector waypoint3;
.vector waypoint4;
.vector waypoint5;
.vector lastSighted;
.entity target1;
.entity target2;
.entity target3;
float fActiveClients1;
float fActiveClients2;
float fMaxClients;
float BOT_COUNT;
float sv_friction;
float sv_gravity;
float sv_accelerate;
float sv_maxspeed;
float sv_stopspeed;
entity fixer;
float userid;
float auto_bot_done;
float (float tno) TeamFortress_TeamGetColor;
float (float v) anglemod;
void () BotInit;
void () BotFrame;
float () BotPreFrame;
float () BotPostFrame;
void () ClientInRankings;
float (entity targ) visible;
void () BotAI;
void () BotTouch;
void () UserInterface;
void (float inp) BotMenu_Input;
void (float inp) BotClassMenu_Input;
void (float inp) BotTeamMenu_Input;
float fResupplyBetweenKills;
float (float clientno) clientBitFlag;
float (float clientno) clientIsActive;
void (float clientno) clientSetUsed;
void (float clientno) clientSetFree;
float () clientNextAvailable;
void (vector whichway) frik_obstructed;
void () CL_KeyMove;
void () SV_Physics_Client;
void () SV_ClientThink;
string () PickAName;
float (float y1, float y2) angcomp;
void (entity e, float chan, string samp, float vol, float atten) frik_sound = #8; 
void (entity client, string s) frik_stuffcmd = #21; 
void (entity client, ...) frik_sprint = #24; 
vector (entity e, float speed) frik_aim = #44; 
void (entity client, string s, ...) frik_centerprint = #73; 
void (entity e) frik_setspawnparms = #78; 
void (float to, float f) frik_WriteByte = #52; 
void (float to, float f) frik_WriteChar = #53; 
void (float to, float f) frik_WriteShort = #54; 
void (float to, float f) frik_WriteLong = #55; 
void (float to, float f) frik_WriteCoord = #56; 
void (float to, float f) frik_WriteAngle = #57; 
void (float to, string s) frik_WriteString = #58; 
void (float to, entity s) frik_WriteEntity = #59; 
string(entity e, string key) frik_infokey = #80; 

string (entity e, string s) infokey =
{
	if (((e == world) || (e.ishuman == TRUE)))
	{
		return (frik_infokey (e, s));
	}
	if ((e.classname == "player"))
	{
		if ((s == "bottomcolor"))
		{
			return (ftos (e.fPants));
		}
		if ((s == "skin"))
		{
			if ((self.playerclass == TF_FLARE_OFF))
			{
				return ("tf_scout");
			}
			else
			{
				if ((self.playerclass == BOT_FIGHTING))
				{
					return ("tf_snipe");
				}
				else
				{
					if ((self.playerclass == BOT_AI_FOLLOW))
					{
						return ("tf_sold");
					}
					else
					{
						if ((self.playerclass == BOT_MOVING))
						{
							return ("tf_demo");
						}
						else
						{
							if ((self.playerclass == BOT_AI_GRAPPLE))
							{
								return ("tf_medic");
							}
							else
							{
								if ((self.playerclass == BOT_AI_FLEE))
								{
									return ("tf_hwguy");
								}
								else
								{
									if ((self.playerclass == BOT_AI_BLAST))
									{
										return ("tf_pyro");
									}
									else
									{
										if ((self.playerclass == BOT_DEFEND))
										{
											return ("tf_spy");
										}
										else
										{
											return ("tf_eng");
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if ((s == "team"))
		{
			return (GetTeamName (e.team_no));
		}
	}
};

void (entity client, string s) stuffcmd =
{
	if (client.ishuman)
	{
		frik_stuffcmd (client, s);
	}
};

void (entity e) setspawnparms =
{
	if (e.ishuman)
	{
		frik_setspawnparms (e);
	}
	else
	{
		SetNewParms ();
	}
};

void (entity client, float level, string s1) sprint =
{
	if (client.ishuman)
	{
		frik_sprint (client, level, s1);
	}
};

void (entity client, float level, string s1, string s2) sprint2 =
{
	if (client.ishuman)
	{
		frik_sprint (client, level, s1, s2);
	}
};

void (entity client, float level, string s1, string s2, string s3) sprint3 =
{
	if (client.ishuman)
	{
		frik_sprint (client, level, s1, s2, s3);
	}
};

void (entity client, float level, string s1, string s2, string s3, string s4) sprint4 =
{
	if (client.ishuman)
	{
		frik_sprint (client, level, s1, s2, s3, s4);
	}
};

void (entity client, float level, string s1, string s2, string s3, string s4, string s5) sprint5 =
{
	if (client.ishuman)
	{
		frik_sprint (client, level, s1, s2, s3, s4, s5);
	}
};

void (entity client, float level, string s1, string s2, string s3, string s4, string s5, string s6) sprint6 =
{
	if (client.ishuman)
	{
		frik_sprint (client, level, s1, s2, s3, s4, s5, s6);
	}
};

void (entity client, string s1) centerprint =
{
	if (client.ishuman)
	{
		frik_centerprint (client, s1);
	}
};

void (entity client, string s1, string s2) centerprint2 =
{
	if (client.ishuman)
	{
		frik_centerprint (client, s1, s2);
	}
};

void (entity client, string s1, string s2, string s3) centerprint3 =
{
	if (client.ishuman)
	{
		frik_centerprint (client, s1, s2, s3);
	}
};

void (entity client, string s1, string s2, string s3, string s4) centerprint4 =
{
	if (client.ishuman)
	{
		frik_centerprint (client, s1, s2, s3, s4);
	}
};

void (entity client, string s1, string s2, string s3, string s4, string s5) centerprint5 =
{
	if (client.ishuman)
	{
		frik_centerprint (client, s1, s2, s3, s4, s5);
	}
};

void (entity client, string s1, string s2, string s3, string s4, string s5, string s6) centerprint6 =
{
	if (client.ishuman)
	{
		frik_centerprint (client, s1, s2, s3, s4, s5, s6);
	}
};

void (entity client, string s1, string s2, string s3, string s4, string s5, string s6, string s7) centerprint7 =
{
	if (client.ishuman)
	{
		frik_centerprint (client, s1, s2, s3, s4, s5, s6, s7);
	}
};

vector (entity e, float sped) aim =
{
	e.missile_speed = sped;
	return (frik_aim (e, sped));
};

void (entity e, float chan, string samp, float vol, float atten) sound =
{
	if ((e.classname == "player"))
	{
		e.f_sound = (time + 0.5);
	}
	frik_sound (e, chan, samp, vol, atten);
};

void (float to, float f) WriteByte =
{
	if (((to == MSG_ONE) && (msg_entity.ishuman != TRUE)))
	{
		return;
	}
	frik_WriteByte (to, f);
};

void (float to, float f) WriteChar =
{
	if (((to == MSG_ONE) && (msg_entity.ishuman != TRUE)))
	{
		return;
	}
	frik_WriteChar (to, f);
};

void (float to, float f) WriteShort =
{
	if (((to == MSG_ONE) && (msg_entity.ishuman != TRUE)))
	{
		return;
	}
	frik_WriteShort (to, f);
};

void (float to, float f) WriteLong =
{
	if (((to == MSG_ONE) && (msg_entity.ishuman != TRUE)))
	{
		return;
	}
	frik_WriteLong (to, f);
};

void (float to, float f) WriteCoord =
{
	if (((to == MSG_ONE) && (msg_entity.ishuman != TRUE)))
	{
		return;
	}
	frik_WriteCoord (to, f);
};

void (float to, float f) WriteAngle =
{
	if (((to == MSG_ONE) && (msg_entity.ishuman != TRUE)))
	{
		return;
	}
	frik_WriteAngle (to, f);
};

void (float to, string s) WriteString =
{
	if (((to == MSG_ONE) && (msg_entity.ishuman != TRUE)))
	{
		return;
	}
	frik_WriteString (to, s);
};

void (float to, entity s) WriteEntity =
{
	if (((to == MSG_ONE) && (msg_entity.ishuman != TRUE)))
	{
		return;
	}
	frik_WriteEntity (to, s);
};
