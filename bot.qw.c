float MSG_UPDATENAME    = 13;
float MSG_UPDATEFRAGS    = 14;
float MSG_UPDATECOLORS    = 17;
float SCOUT    = 1;
float SNIPER    = 2;
float SOLDIER    = 3;
float DEMOMAN    = 4;
float MEDIC    = 5;
float HWGUY    = 6;
float PYRO    = 7;
float SPY    = 8;
float ENGINEER    = 9;
void (float whichteam, float whichClass) botConnect;
void (entity bot) botDisconnect;
void (float clientno) botInvalidClientNo;
void (float clientno, float clientfrags) svcUpdateFrags;
void (float clientno, float clientping) svcUpdatePing;
void (float clientno, float cliententertime) svcUpdateEnterTime;
void (float clientno, float clientid, float clientshirt, float clientpants, string clientname, float botteam, float botskin) svcUpdateUserInfo;

void () ClientFixRankings =
{
	local float cno;
	local entity bott;

	self.ishuman = TRUE;
	if ((self.switch_wallhug > time))
	{
		return;
	}
	self.switch_wallhug = TF_FLARE_LIT;
	bott = nextent (world);
	cno = TF_FLARE_LIT;
	while ((cno < fMaxClients))
	{
		if ((!bott.ishuman && clientIsActive (cno)))
		{
			svcUpdatePing (bott.fClientNo, bott.botskill);
			svcUpdateEnterTime (bott.fClientNo, (time - bott.fEnterTime));
			svcUpdateUserInfo (bott.fClientNo, bott.fUserID, bott.fShirt, bott.fPants, bott.netname, bott.team_no, bott.skin);
			svcUpdateFrags (bott.fClientNo, bott.frags);
		}
		cno = (cno + TF_FLARE_OFF);
		bott = nextent (bott);
	}
};

void () ClientInRankings =
{
	local float cno;

	if ((self.ishuman == BOT_FIGHTING))
	{
		self.ishuman = FALSE;
		return;
	}
	cno = (self.colormap - TF_FLARE_OFF);
	botInvalidClientNo (cno);
	clientSetUsed (cno);
	self.fClientNo = cno;
	self.ishuman = TRUE;
	self.switch_wallhug = (time + TF_FLARE_OFF);
};

void (float clientno, float clientfrags) svcUpdateFrags =
{
	WriteByte (BOT_FIGHTING, 14);
	WriteByte (BOT_FIGHTING, clientno);
	WriteShort (BOT_FIGHTING, clientfrags);
};

void (float clientno, float clientping) svcUpdatePing =
{
	WriteByte (BOT_FIGHTING, 36);
	WriteByte (BOT_FIGHTING, clientno);
	WriteShort (BOT_FIGHTING, clientping);
};

void (float clientno, float cliententertime) svcUpdateEnterTime =
{
	WriteByte (BOT_FIGHTING, 37);
	WriteByte (BOT_FIGHTING, clientno);
	WriteLong (BOT_FIGHTING, cliententertime);
};

void (float clientno, float clientid, float clientshirt, float clientpants, string clientname, float botteam, float botskin) svcUpdateUserInfo =
{
	WriteByte (BOT_FIGHTING, 40);
	WriteByte (BOT_FIGHTING, clientno);
	WriteLong (BOT_FIGHTING, clientid);
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 109);
	WriteByte (BOT_FIGHTING, 115);
	WriteByte (BOT_FIGHTING, 103);
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 49);
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 114);
	WriteByte (BOT_FIGHTING, 97);
	WriteByte (BOT_FIGHTING, 116);
	WriteByte (BOT_FIGHTING, 101);
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 53);
	WriteByte (BOT_FIGHTING, 48);
	WriteByte (BOT_FIGHTING, 48);
	WriteByte (BOT_FIGHTING, 48);
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 119);
	WriteByte (BOT_FIGHTING, 95);
	WriteByte (BOT_FIGHTING, 115);
	WriteByte (BOT_FIGHTING, 119);
	WriteByte (BOT_FIGHTING, 105);
	WriteByte (BOT_FIGHTING, 116);
	WriteByte (BOT_FIGHTING, 99);
	WriteByte (BOT_FIGHTING, 104);
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 50);
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 98);
	WriteByte (BOT_FIGHTING, 95);
	WriteByte (BOT_FIGHTING, 115);
	WriteByte (BOT_FIGHTING, 119);
	WriteByte (BOT_FIGHTING, 105);
	WriteByte (BOT_FIGHTING, 116);
	WriteByte (BOT_FIGHTING, 99);
	WriteByte (BOT_FIGHTING, 104);
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 50);
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 110);
	WriteByte (BOT_FIGHTING, 111);
	WriteByte (BOT_FIGHTING, 97);
	WriteByte (BOT_FIGHTING, 105);
	WriteByte (BOT_FIGHTING, 109);
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 48);
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 115);
	WriteByte (BOT_FIGHTING, 112);
	WriteByte (BOT_FIGHTING, 101);
	WriteByte (BOT_FIGHTING, 99);
	WriteByte (BOT_FIGHTING, 116);
	WriteByte (BOT_FIGHTING, 97);
	WriteByte (BOT_FIGHTING, 116);
	WriteByte (BOT_FIGHTING, 111);
	WriteByte (BOT_FIGHTING, 114);
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 48);
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 112);
	WriteByte (BOT_FIGHTING, 109);
	WriteByte (BOT_FIGHTING, 111);
	WriteByte (BOT_FIGHTING, 100);
	WriteByte (BOT_FIGHTING, 101);
	WriteByte (BOT_FIGHTING, 108);
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 49);
	WriteByte (BOT_FIGHTING, 51);
	WriteByte (BOT_FIGHTING, 56);
	WriteByte (BOT_FIGHTING, 52);
	WriteByte (BOT_FIGHTING, 53);
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 101);
	WriteByte (BOT_FIGHTING, 109);
	WriteByte (BOT_FIGHTING, 111);
	WriteByte (BOT_FIGHTING, 100);
	WriteByte (BOT_FIGHTING, 101);
	WriteByte (BOT_FIGHTING, 108);
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 54);
	WriteByte (BOT_FIGHTING, 57);
	WriteByte (BOT_FIGHTING, 54);
	WriteByte (BOT_FIGHTING, 55);
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 98);
	WriteByte (BOT_FIGHTING, 111);
	WriteByte (BOT_FIGHTING, 116);
	WriteByte (BOT_FIGHTING, 116);
	WriteByte (BOT_FIGHTING, 111);
	WriteByte (BOT_FIGHTING, 109);
	WriteByte (BOT_FIGHTING, 99);
	WriteByte (BOT_FIGHTING, 111);
	WriteByte (BOT_FIGHTING, 108);
	WriteByte (BOT_FIGHTING, 111);
	WriteByte (BOT_FIGHTING, 114);
	WriteByte (BOT_FIGHTING, 92);
	if ((clientpants > BOT_AI_FLAGRUN))
	{
		WriteByte (BOT_FIGHTING, 49);
		WriteByte (BOT_FIGHTING, (38 + clientpants));
	}
	else
	{
		WriteByte (BOT_FIGHTING, (48 + clientpants));
	}
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 116);
	WriteByte (BOT_FIGHTING, 111);
	WriteByte (BOT_FIGHTING, 112);
	WriteByte (BOT_FIGHTING, 99);
	WriteByte (BOT_FIGHTING, 111);
	WriteByte (BOT_FIGHTING, 108);
	WriteByte (BOT_FIGHTING, 111);
	WriteByte (BOT_FIGHTING, 114);
	WriteByte (BOT_FIGHTING, 92);
	if ((clientshirt > BOT_AI_FLAGRUN))
	{
		WriteByte (BOT_FIGHTING, 49);
		WriteByte (BOT_FIGHTING, (38 + clientshirt));
	}
	else
	{
		WriteByte (BOT_FIGHTING, (48 + clientshirt));
	}
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 116);
	WriteByte (BOT_FIGHTING, 101);
	WriteByte (BOT_FIGHTING, 97);
	WriteByte (BOT_FIGHTING, 109);
	WriteByte (BOT_FIGHTING, 92);
	if ((botteam == TF_FLARE_OFF))
	{
		WriteByte (BOT_FIGHTING, 98);
		WriteByte (BOT_FIGHTING, 108);
		WriteByte (BOT_FIGHTING, 117);
		WriteByte (BOT_FIGHTING, 101);
	}
	else
	{
		if ((botteam == BOT_FIGHTING))
		{
			WriteByte (BOT_FIGHTING, 114);
			WriteByte (BOT_FIGHTING, 101);
			WriteByte (BOT_FIGHTING, 100);
		}
	}
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 115);
	WriteByte (BOT_FIGHTING, 107);
	WriteByte (BOT_FIGHTING, 105);
	WriteByte (BOT_FIGHTING, 110);
	WriteByte (BOT_FIGHTING, 92);
	if ((botskin == TF_FLARE_OFF))
	{
		WriteByte (BOT_FIGHTING, 116);
		WriteByte (BOT_FIGHTING, 102);
		WriteByte (BOT_FIGHTING, 95);
		WriteByte (BOT_FIGHTING, 115);
		WriteByte (BOT_FIGHTING, 99);
		WriteByte (BOT_FIGHTING, 111);
		WriteByte (BOT_FIGHTING, 117);
		WriteByte (BOT_FIGHTING, 116);
	}
	else
	{
		if ((botskin == BOT_FIGHTING))
		{
			WriteByte (BOT_FIGHTING, 116);
			WriteByte (BOT_FIGHTING, 102);
			WriteByte (BOT_FIGHTING, 95);
			WriteByte (BOT_FIGHTING, 115);
			WriteByte (BOT_FIGHTING, 110);
			WriteByte (BOT_FIGHTING, 105);
			WriteByte (BOT_FIGHTING, 112);
			WriteByte (BOT_FIGHTING, 101);
		}
		else
		{
			if ((botskin == BOT_AI_FOLLOW))
			{
				WriteByte (BOT_FIGHTING, 116);
				WriteByte (BOT_FIGHTING, 102);
				WriteByte (BOT_FIGHTING, 95);
				WriteByte (BOT_FIGHTING, 115);
				WriteByte (BOT_FIGHTING, 111);
				WriteByte (BOT_FIGHTING, 108);
				WriteByte (BOT_FIGHTING, 100);
			}
			else
			{
				if ((botskin == BOT_MOVING))
				{
					WriteByte (BOT_FIGHTING, 116);
					WriteByte (BOT_FIGHTING, 102);
					WriteByte (BOT_FIGHTING, 95);
					WriteByte (BOT_FIGHTING, 100);
					WriteByte (BOT_FIGHTING, 101);
					WriteByte (BOT_FIGHTING, 109);
					WriteByte (BOT_FIGHTING, 111);
				}
				else
				{
					if ((botskin == BOT_AI_GRAPPLE))
					{
						WriteByte (BOT_FIGHTING, 116);
						WriteByte (BOT_FIGHTING, 102);
						WriteByte (BOT_FIGHTING, 95);
						WriteByte (BOT_FIGHTING, 109);
						WriteByte (BOT_FIGHTING, 101);
						WriteByte (BOT_FIGHTING, 100);
						WriteByte (BOT_FIGHTING, 105);
						WriteByte (BOT_FIGHTING, 99);
					}
					else
					{
						if ((botskin == BOT_AI_FLEE))
						{
							WriteByte (BOT_FIGHTING, 116);
							WriteByte (BOT_FIGHTING, 102);
							WriteByte (BOT_FIGHTING, 95);
							WriteByte (BOT_FIGHTING, 104);
							WriteByte (BOT_FIGHTING, 119);
							WriteByte (BOT_FIGHTING, 103);
							WriteByte (BOT_FIGHTING, 117);
							WriteByte (BOT_FIGHTING, 121);
						}
						else
						{
							if ((botskin == BOT_AI_BLAST))
							{
								WriteByte (BOT_FIGHTING, 116);
								WriteByte (BOT_FIGHTING, 102);
								WriteByte (BOT_FIGHTING, 95);
								WriteByte (BOT_FIGHTING, 112);
								WriteByte (BOT_FIGHTING, 121);
								WriteByte (BOT_FIGHTING, 114);
								WriteByte (BOT_FIGHTING, 111);
							}
							else
							{
								if ((botskin == BOT_DEFEND))
								{
									WriteByte (BOT_FIGHTING, 116);
									WriteByte (BOT_FIGHTING, 102);
									WriteByte (BOT_FIGHTING, 95);
									WriteByte (BOT_FIGHTING, 115);
									WriteByte (BOT_FIGHTING, 112);
									WriteByte (BOT_FIGHTING, 121);
								}
								else
								{
									if ((botskin == BOT_AI_FLAGRUN))
									{
										WriteByte (BOT_FIGHTING, 116);
										WriteByte (BOT_FIGHTING, 102);
										WriteByte (BOT_FIGHTING, 95);
										WriteByte (BOT_FIGHTING, 101);
										WriteByte (BOT_FIGHTING, 110);
										WriteByte (BOT_FIGHTING, 103);
									}
									else
									{
										WriteByte (BOT_FIGHTING, 98);
										WriteByte (BOT_FIGHTING, 97);
										WriteByte (BOT_FIGHTING, 115);
										WriteByte (BOT_FIGHTING, 101);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	WriteByte (BOT_FIGHTING, 92);
	WriteByte (BOT_FIGHTING, 110);
	WriteByte (BOT_FIGHTING, 97);
	WriteByte (BOT_FIGHTING, 109);
	WriteByte (BOT_FIGHTING, 101);
	WriteByte (BOT_FIGHTING, 92);
	WriteString (BOT_FIGHTING, clientname);
};

float (float clientno) clientBitFlag =
{
	local float bitflag;

	bitflag = TF_FLARE_OFF;
	while ((clientno > TF_FLARE_LIT))
	{
		bitflag = (bitflag * BOT_FIGHTING);
		clientno = (clientno - TF_FLARE_OFF);
	}
	return (bitflag);
};

float (float clientno) clientIsActive =
{
	if ((clientno > BOT_RESUPPLYING))
	{
		if ((fActiveClients2 & clientBitFlag ((clientno - BOT_RESUPPLYING))))
		{
			return (TF_FLARE_OFF);
		}
	}
	else
	{
		if ((fActiveClients1 & clientBitFlag (clientno)))
		{
			return (TF_FLARE_OFF);
		}
	}
	return (TF_FLARE_LIT);
};

void (float clientno) clientSetUsed =
{
	if ((clientno > BOT_RESUPPLYING))
	{
		fActiveClients2 = (fActiveClients2 | clientBitFlag ((clientno - BOT_RESUPPLYING)));
	}
	else
	{
		fActiveClients1 = (fActiveClients1 | clientBitFlag (clientno));
	}
};

void (float clientno) clientSetFree =
{
	if ((clientno > BOT_RESUPPLYING))
	{
		fActiveClients2 = (fActiveClients2 - (fActiveClients2 & clientBitFlag ((clientno - BOT_RESUPPLYING))));
	}
	else
	{
		fActiveClients1 = (fActiveClients1 - (fActiveClients1 & clientBitFlag (clientno)));
	}
};

float () clientNextAvailable =
{
	local float clientno;

	clientno = (fMaxClients - BOT_FIGHTING);
	while ((clientno >= TF_FLARE_LIT))
	{
		if (!clientIsActive (clientno))
		{
			return (clientno);
		}
		clientno = (clientno - TF_FLARE_OFF);
	}
	return (CONTENT_EMPTY);
};

float () BotPreFrame =
{
	if ((self.ishuman == TRUE))
	{
		if (self.switch_wallhug)
		{
			ClientFixRankings ();
		}
	}
	return (FALSE);
};

float () BotPostFrame =
{
	UserInterface ();
	return (FALSE);
};

void (string h) BotSay =
{
	WriteByte (MSG_ALL, BOT_DEFEND);
	WriteByte (MSG_ALL, BOT_AI_FOLLOW);
	WriteByte (MSG_ALL, TF_FLARE_OFF);
	WriteString (MSG_ALL, self.netname);
	WriteByte (MSG_ALL, BOT_DEFEND);
	WriteByte (MSG_ALL, BOT_AI_FOLLOW);
	WriteByte (MSG_ALL, BOT_FIGHTING);
	WriteString (MSG_ALL, h);
};

void () BotSayInit =
{
	WriteByte (MSG_ALL, BOT_DEFEND);
	WriteByte (MSG_ALL, BOT_AI_FOLLOW);
	WriteByte (MSG_ALL, TF_FLARE_OFF);
	WriteString (MSG_ALL, self.netname);
};

void (string h) BotSay2 =
{
	WriteByte (MSG_ALL, BOT_DEFEND);
	WriteByte (MSG_ALL, BOT_AI_FOLLOW);
	WriteByte (MSG_ALL, BOT_FIGHTING);
	WriteString (MSG_ALL, h);
};

void () BotInit =
{
	local entity ent;
	local entity fisent;
	local float numents;

	ent = nextent (world);
	while ((ent.classname != "worldspawn"))
	{
		fMaxClients = (fMaxClients + TF_FLARE_OFF);
		ent = nextent (ent);
	}
	ent = nextent (world);
	while ((numents < fMaxClients))
	{
		fisent = spawn ();
		ent.phys_obj = fisent;
		fisent.owner = ent;
		numents = (numents + TF_FLARE_OFF);
		ent = nextent (ent);
	}
	fResupplyBetweenKills = TF_FLARE_OFF;
};

entity (float num) GetClientEntity =
{
	local entity upsy;

	upsy = world;
	num = (num + TF_FLARE_OFF);
	while ((num > TF_FLARE_LIT))
	{
		num = (num - TF_FLARE_OFF);
		upsy = nextent (upsy);
	}
	return (upsy);
};

void (float whichteam, float whichClass) botConnect =
{
	local float clientno;
	local entity bot;
	local entity uself;
	local string g;

	clientno = clientNextAvailable ();
	uself = self;
	if ((clientno == CONTENT_EMPTY))
	{
		bprint (BOT_FIGHTING, "Unable to connect a bot, server is full.\n");
		return;
	}
	clientSetUsed (clientno);
	BOT_COUNT = (BOT_COUNT + TF_FLARE_OFF);
	bot = GetClientEntity (clientno);
	userid = (userid + TF_FLARE_OFF);
	bot.fUserID = userid;
	bot.fClientNo = clientno;
	bot.colormap = (clientno + TF_FLARE_OFF);
	self = bot;
	bot.netname = PickAName ();
	bot.botskill = TF_FLARE_OFF;
	bot.team = (bot.fPants + TF_FLARE_OFF);
	bot.fEnterTime = time;
	svcUpdateFrags (bot.fClientNo, bot.frags);
	svcUpdatePing (bot.fClientNo, bot.botskill);
	svcUpdateEnterTime (bot.fClientNo, (time - bot.fEnterTime));
	svcUpdateUserInfo (bot.fClientNo, bot.fUserID, bot.fShirt, bot.fPants, bot.netname, whichteam, whichClass);
	SetNewParms ();
	self.ishuman = BOT_FIGHTING;
	ClientConnect ();
	PutClientInServer ();
	if (whichteam)
	{
		self.team_no = whichteam;
	}
	else
	{
		self.team_no = BOT_AI_GRAPPLE;
	}
	self.skin = whichClass;
	ClearAllWaypoints ();
	ClearAllTargets ();
	self.action = BOT_RESUPPLYING;
	self.obs_time = TF_FLARE_LIT;
	self.oldAction = BOT_IDLE;
	self.pipeLocation = '0 0 0';
	self = uself;
};

void (entity bot) botDisconnect =
{
	local entity whoself;

	whoself = self;
	self = bot;
	BOT_COUNT = (BOT_COUNT - TF_FLARE_OFF);
	ClientDisconnect ();
	if ((bot.fClientNo != CONTENT_EMPTY))
	{
		self.tfrags = TF_FLARE_LIT;
		self.frags = TF_FLARE_LIT;
		self.skin = TF_FLARE_LIT;
		self.real_frags = TF_FLARE_LIT;
		self.origin = '0 0 0';
		self.netname = "";
		self.classname = "";
		self.health = TF_FLARE_LIT;
		self.items = TF_FLARE_LIT;
		self.armorvalue = TF_FLARE_LIT;
		self.weapons_carried = TF_FLARE_LIT;
		self.current_weapon = TF_FLARE_LIT;
		self.playerclass = TF_FLARE_LIT;
		self.weaponmodel = "";
		self.phys_obj.modelindex = TF_FLARE_LIT;
		self.ammo_shells = TF_FLARE_LIT;
		self.ammo_nails = TF_FLARE_LIT;
		self.ammo_rockets = TF_FLARE_LIT;
		self.ammo_cells = TF_FLARE_LIT;
		svcUpdateFrags (bot.fClientNo, TF_FLARE_LIT);
		svcUpdatePing (bot.fClientNo, TF_FLARE_LIT);
		svcUpdateEnterTime (bot.fClientNo, TF_FLARE_LIT);
		svcUpdateUserInfo (bot.fClientNo, TF_FLARE_LIT, TF_FLARE_LIT, TF_FLARE_LIT, string_null, TF_FLARE_LIT, TF_FLARE_LIT);
		clientSetFree (bot.fClientNo);
		bot.fClientNo = CONTENT_EMPTY;
	}
	self = whoself;
};

void (float clientno) botInvalidClientNo =
{
	local entity bot;

	bot = find (world, classname, "player");
	while (bot)
	{
		if (((bot.fClientNo == clientno) && !bot.ishuman))
		{
			bot.fClientNo = CONTENT_EMPTY;
			botDisconnect (bot);
			return;
		}
		bot = find (bot, classname, "player");
	}
};

void () BotFrame =
{
	local float num;
	local float num2;

	num = stof (infokey (world, "skill"));
	auto_bot_done = TF_FLARE_OFF;
	sv_maxspeed = cvar ("sv_maxspeed");
	sv_gravity = cvar ("sv_gravity");
	sv_friction = cvar ("sv_friction");
	sv_accelerate = cvar ("sv_accelerate");
	sv_stopspeed = cvar ("sv_stopspeed");
	self = nextent (world);
	num = TF_FLARE_LIT;
	while ((num < fMaxClients))
	{
		if ((self.ishuman == FALSE))
		{
			if (clientIsActive (num))
			{
				sv_maxspeed = self.maxfbspeed;
				if ((self.tfrags != self.frags))
				{
					svcUpdateFrags (self.fClientNo, self.frags);
				}
				CL_KeyMove ();
				SV_ClientThink ();
				SV_Physics_Client ();
				if (self.phys_obj)
				{
					setmodel (self.phys_obj, "progs/player.mdl");
					self.phys_obj.modelindex = self.modelindex;
					self.phys_obj.frame = self.frame;
					self.phys_obj.angles = self.angles;
					self.phys_obj.avelocity = self.velocity;
					self.phys_obj.colormap = self.colormap;
				}
				if ((((self.playerclass == BOT_DEFEND) && (self.undercover_team != TF_FLARE_LIT)) && teamplay))
				{
					if ((TeamFortress_TeamGetColor (self.undercover_team) != self.team))
					{
						num2 = (TeamFortress_TeamGetColor (self.undercover_team) - TF_FLARE_OFF);
						self.fPants = num2;
						self.fShirt = num2;
						self.team = (self.fPants + TF_FLARE_OFF);
						svcUpdateFrags (self.fClientNo, self.frags);
						svcUpdatePing (self.fClientNo, self.botskill);
						svcUpdateEnterTime (self.fClientNo, (time - self.fEnterTime));
						svcUpdateUserInfo (self.fClientNo, self.fUserID, self.fShirt, self.fPants, self.netname, self.team_no, self.skin);
					}
					self.team = TeamFortress_TeamGetColor (self.undercover_team);
				}
				else
				{
					if (((TeamFortress_TeamGetColor (self.team_no) != self.team) && teamplay))
					{
						num2 = (TeamFortress_TeamGetColor (self.team_no) - TF_FLARE_OFF);
						self.fPants = num2;
						self.fShirt = num2;
						self.team = (self.fPants + TF_FLARE_OFF);
						svcUpdateFrags (self.fClientNo, self.frags);
						svcUpdatePing (self.fClientNo, self.botskill);
						svcUpdateEnterTime (self.fClientNo, (time - self.fEnterTime));
						svcUpdateUserInfo (self.fClientNo, self.fUserID, self.fShirt, self.fPants, self.netname, self.team_no, self.skin);
					}
				}
			}
		}
		self = nextent (self);
		num = (num + TF_FLARE_OFF);
	}
};
