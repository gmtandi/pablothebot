
void () BotAI =
{
	local float area;
	local string strTemp;
	local float movementOK;
	local float fTemp;
	local entity eTemp;
	local entity eGren;
	local vector vTemp;

	if ((self.health <= TF_FLARE_LIT))
	{
		if ((self.action & (BOT_RESUPPLYING + BOT_MOVING)))
		{
			fTemp = TF_FLARE_LIT;
		}
		if ((self.fBotMessageTime == TF_FLARE_LIT))
		{
			self.fBotMessageTime = ((time + (fResupplyBetweenKills * 1.5)) + (random () * (BOT_COUNT * 0.3)));
			return;
		}
		if ((self.fBotMessageTime < time))
		{
			ClearAllWaypoints ();
			ClearAllTargets ();
			self.obs_time = TF_FLARE_LIT;
			self.action = BOT_IDLE;
			self.button0 = floor ((random () * BOT_FIGHTING));
			self.button1 = TF_FLARE_LIT;
			self.button2 = TF_FLARE_LIT;
			self.keys = TF_FLARE_LIT;
			self.fBotMessageTime = TF_FLARE_LIT;
			return;
		}
	}
	if (((self.action & (BOT_DEFEND + BOT_FIGHTING)) && (self.FlashTime == TF_FLARE_LIT)))
	{
		FindTargets ();
	}
	if ((self.target1 != world))
	{
		AttackTargets ();
	}
	if ((self.action & BOT_RESUPPLYING))
	{
		ReloadWeapons ();
		if ((self.team_no == TF_FLARE_OFF))
		{
			if ((vlen ((self.origin - '256 -840 -936')) < BOT_IMPULSE))
			{
				self.waypoint1 = '256 -840 -936';
			}
			else
			{
				self.waypoint1 = '256 -550 -936';
				self.waypoint2 = '256 -840 -936';
			}
		}
		else
		{
			if ((vlen ((self.origin - '256 430 -936')) < BOT_IMPULSE))
			{
				self.waypoint1 = '256 430 -936';
			}
			else
			{
				self.waypoint1 = '256 200 -936';
				self.waypoint2 = '256 430 -936';
			}
		}
		self.action = BOT_MOVING;
	}
	if ((self.action & BOT_DEFEND))
	{
		PickBestWeapon ();
		if (((CheckForResupply () == TRUE) && fResupplyBetweenKills))
		{
			GoForResupply ();
		}
	}
	if ((self.action & BOT_IDLE))
	{
		ReloadWeapons ();
		if (((CheckForResupply () == TRUE) && fResupplyBetweenKills))
		{
			GoForResupply ();
		}
		else
		{
			if ((self.team_no == TF_FLARE_OFF))
			{
				if ((self.origin_y < -600))
				{
					GotoLocation ('256 -550 -936');
				}
				else
				{
					self.keys = TF_FLARE_LIT;
					self.action = BOT_DEFEND;
				}
			}
			else
			{
				if ((self.origin_y > 250))
				{
					GotoLocation ('256 200 -936');
				}
				else
				{
					self.keys = TF_FLARE_LIT;
					self.action = BOT_DEFEND;
				}
			}
		}
	}
	if ((self.action == BOT_MOVING))
	{
		PickBestWeapon ();
		ReloadWeapons ();
		DoMovement ();
	}
	if (self.debug_report_action)
	{
		bprint (BOT_FIGHTING, "My client number is:");
		strTemp = ftos (self.fClientNo);
		bprint (BOT_FIGHTING, strTemp);
		bprint (BOT_FIGHTING, "\n");
		self.debug_report_action = TF_FLARE_LIT;
	}
	DodgeEnemyGrenades ();
	if ((self.FlashTime > TF_FLARE_LIT))
	{
		if ((self.FlashTime > 23))
		{
			ClearAllTargets ();
			self.keys = KEY_MOVEBACK;
			self.button0 = TF_FLARE_OFF;
		}
		else
		{
			self.keys = TF_FLARE_LIT;
			self.button0 = TF_FLARE_LIT;
			self.FlashTime = TF_FLARE_LIT;
			self.action = BOT_IDLE;
		}
	}
	eTemp = find (world, classname, "timer");
	while ((eTemp != world))
	{
		if ((eTemp.think == ConcussionGrenadeTimer))
		{
			if ((eTemp.owner == self))
			{
				if ((eTemp.health > 80))
				{
					self.v_angle_x = (self.v_angle_x + (18 * (random () - 0.5)));
					self.v_angle_y = (self.v_angle_y + (18 * (random () - 0.5)));
				}
				else
				{
					if ((eTemp.health > 60))
					{
						self.v_angle_x = (self.v_angle_x + (BOT_AI_FLAGRUN * (random () - 0.5)));
						self.v_angle_y = (self.v_angle_y + (BOT_AI_FLAGRUN * (random () - 0.5)));
					}
					else
					{
						eTemp.health = BOT_AI_GRAPPLE;
					}
				}
			}
		}
		eTemp = find (eTemp, classname, "timer");
	}
	if ((self.obs_time > time))
	{
		if ((self.action & (BOT_DEFEND + BOT_IDLE)))
		{
			self.obs_time = TF_FLARE_LIT;
		}
		else
		{
			self.keys = self.keys;
		}
	}
	if (self.current_menu)
	{
		self.impulse = BotImpulseMenu ();
	}
	if ((self.target1 == world))
	{
		if (((self.tfstate & TF_FLARE_OFF) || (self.tfstate & FL_PARTIALGROUND)))
		{
			eGren = world;
			eTemp = find (world, classname, "GrenadeTimer");
			while (eTemp)
			{
				if ((eTemp.owner == self))
				{
					eGren = eTemp;
				}
				eTemp = find (eTemp, classname, "GrenadeTimer");
			}
			if ((eGren != world))
			{
				if ((eGren.heat < (time + 0.6)))
				{
					self.impulse = 152;
				}
			}
		}
	}
};
