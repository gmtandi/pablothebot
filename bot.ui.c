.float debug_report_loc;
.float debug_report_action;
.float debug_jump;
.float fBotMessageCounter;
.float fBotMessageTime;
.string sBotMessageLine1;
.float SpeedTime;

void () UserInterface =
{
	local float iClass;
	local entity bot;
	local string strTemp;

	if ((time < self.fBotMessageTime))
	{
		if ((self.fBotMessageCounter < 25))
		{
			self.fBotMessageCounter = (self.fBotMessageCounter + TF_FLARE_OFF);
		}
		else
		{
			self.fBotMessageCounter = TF_FLARE_LIT;
			CenterPrint (self, self.sBotMessageLine1);
		}
	}
	if ((self.impulse == BOT_IMPULSE))
	{
		if (fResupplyBetweenKills)
		{
			self.sBotMessageLine1 = "=== Bot Menu ===\n\n“.. Add a Bot                 \n”.. Kick a Bot                \n•.. No resupplying            \n—.. Nothing                   \n\nBy PáâìOŽTèEŽGòåáT";
		}
		else
		{
			self.sBotMessageLine1 = "=== Bot Menu ===\n\n“.. Add a Bot                 \n”.. Kick a Bot                \n•.. Resupply between kills    \n—.. Nothing                   \n\nBy PáâìOŽTèEŽGòåáT";
		}
		self.current_menu = BOT_IMPULSE;
		self.fBotMessageTime = (time + BOT_MOVING);
	}
	else
	{
		if ((self.impulse == (BOT_IMPULSE + TF_FLARE_OFF)))
		{
			bprint (self.current_weapon, ftos (self.current_weapon));
			bprint (BOT_FIGHTING, "\n");
			self.impulse = TF_FLARE_LIT;
		}
	}
};

void (float inp) BotClassMenu_Input =
{
	if (((inp < TF_FLARE_OFF) || (inp > BOT_AI_FLAGRUN)))
	{
		return;
	}
	self.impulse = TF_FLARE_LIT;
	self.fBotMessageTime = TF_FLARE_LIT;
	self.current_menu = TF_FLARE_LIT;
	CenterPrint (self, "\n");
	botConnect (self.obs_time, inp);
};

void (float inp) BotTeamMenu_Input =
{
	if (((inp < TF_FLARE_OFF) || (inp > BOT_FIGHTING)))
	{
		return;
	}
	self.obs_time = inp;
	CenterPrint (self, "\n");
	self.sBotMessageLine1 = "=== Choose his class ===\n\n“.. Scout   \n”.. Sniper  \n•.. Soldier \n–.. Demoman \n—.. Medic   \n˜.. Hvwep   \n™.. Pyro    \nš.. Spy     \n›.. Engineer\n";
	self.current_menu = 201;
	self.fBotMessageTime = (time + BOT_MOVING);
	self.impulse = TF_FLARE_LIT;
};

void (float inp) BotMenu_Input =
{
	local entity eTemp;

	if ((inp == TF_FLARE_OFF))
	{
		CenterPrint (self, "\n");
		self.sBotMessageLine1 = "=== Choose his team ===\n\n“.. Blue\n”.. Red \n\n";
		self.current_menu = 202;
		self.fBotMessageTime = (time + BOT_MOVING);
		self.impulse = TF_FLARE_LIT;
	}
	else
	{
		if ((inp == BOT_FIGHTING))
		{
			CenterPrint (self, "\n");
			self.impulse = TF_FLARE_LIT;
			self.fBotMessageTime = TF_FLARE_LIT;
			self.current_menu = TF_FLARE_LIT;
			eTemp = find (world, classname, "player");
			while (eTemp)
			{
				if (!eTemp.ishuman)
				{
					botDisconnect (eTemp);
					return;
				}
				eTemp = find (eTemp, classname, "player");
			}
			CenterPrint (self, "No bots to kick.\n");
		}
		else
		{
			if ((inp == BOT_AI_FOLLOW))
			{
				fResupplyBetweenKills = !fResupplyBetweenKills;
				CenterPrint (self, "\n");
				self.impulse = TF_FLARE_LIT;
				self.fBotMessageTime = TF_FLARE_LIT;
				self.current_menu = TF_FLARE_LIT;
			}
			else
			{
				if ((inp == BOT_AI_GRAPPLE))
				{
					CenterPrint (self, "\n");
					self.impulse = TF_FLARE_LIT;
					self.fBotMessageTime = TF_FLARE_LIT;
					self.current_menu = TF_FLARE_LIT;
				}
			}
		}
	}
};
