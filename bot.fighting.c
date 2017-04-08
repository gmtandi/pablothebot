
void () ReloadWeapons =
{
	if (((self.tfstate & TF_FLARE_OFF) || (self.tfstate & FL_PARTIALGROUND)))
	{
		return;
	}
	if (((self.weapons_carried & 8192) && (self.reload_rocket_launcher != TF_FLARE_LIT)))
	{
		if ((self.current_weapon == 8192))
		{
			self.impulse = 173;
		}
		else
		{
			self.impulse = BOT_AI_BLAST;
		}
		return;
	}
	else
	{
		if (((self.weapons_carried & FL_WATERJUMP) && (self.reload_grenade_launcher != TF_FLARE_LIT)))
		{
			if ((self.current_weapon == FL_WATERJUMP))
			{
				self.impulse = 173;
			}
			else
			{
				self.impulse = BOT_AI_FLEE;
			}
			return;
		}
		else
		{
			if (((self.weapons_carried & FL_ITEM) && (self.reload_super_shotgun != TF_FLARE_LIT)))
			{
				if ((self.current_weapon == FL_ITEM))
				{
					self.impulse = 173;
				}
				else
				{
					self.impulse = BOT_AI_FOLLOW;
				}
				return;
			}
			else
			{
				if (((self.weapons_carried & 128) && (self.reload_shotgun != TF_FLARE_LIT)))
				{
					if ((self.current_weapon == 128))
					{
						self.impulse = 173;
					}
					else
					{
						self.impulse = BOT_FIGHTING;
					}
					return;
				}
			}
		}
	}
};

float () AllTargetsFull =
{
	if ((self.target3 == world))
	{
		return (TF_FLARE_LIT);
	}
	else
	{
		return (TF_FLARE_OFF);
	}
};

void (entity targetToAdd) AddTarget =
{
	if ((((self.target1 == targetToAdd) || (self.target2 == targetToAdd)) || (self.target3 == targetToAdd)))
	{
		return;
	}
	if ((self.target1 == world))
	{
		self.target1 = targetToAdd;
	}
	else
	{
		if ((self.target2 == world))
		{
			self.target2 = targetToAdd;
		}
		else
		{
			if ((self.target3 == world))
			{
				self.target3 = targetToAdd;
			}
			else
			{
				return;
			}
		}
	}
	sound (self, TF_FLARE_OFF, "weapons/turrspot.wav", TF_FLARE_OFF, TF_FLARE_OFF);
	self.action = BOT_FIGHTING;
	targetToAdd.lastSighted = targetToAdd.origin;
};

void (float targetToClear) ClearTarget =
{
	if ((targetToClear == BOT_FIGHTING))
	{
		self.target2 = self.target3;
		self.target3 = world;
	}
	else
	{
		if ((targetToClear == BOT_AI_FOLLOW))
		{
			self.target3 = world;
		}
		else
		{
			self.target1 = self.target2;
			self.target2 = self.target3;
			self.target3 = world;
		}
	}
	if ((self.target1 == world))
	{
		self.action = BOT_IDLE;
		self.button0 = TF_FLARE_LIT;
		self.button2 = TF_FLARE_LIT;
		self.keys = TF_FLARE_LIT;
		self.impulse = 152;
	}
};

void () ClearAllTargets =
{
	self.target1 = world;
	self.target2 = world;
	self.target3 = world;
	self.button0 = TF_FLARE_LIT;
	self.button2 = TF_FLARE_LIT;
};

void () PickBestWeapon =
{
	local float targetdistance;
	local entity eGren;
	local entity eTemp;

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
	if (((eGren != world) && (eGren.heat < 0.5)))
	{
		return;
	}
	if ((self.playerclass == TF_FLARE_OFF))
	{
		if ((self.ammo_nails > TF_FLARE_LIT))
		{
			self.impulse = BOT_MOVING;
			return;
		}
		else
		{
			if ((self.ammo_shells > TF_FLARE_LIT))
			{
				self.impulse = BOT_FIGHTING;
				return;
			}
		}
	}
	if ((self.playerclass == BOT_FIGHTING))
	{
		if ((self.ammo_shells > TF_FLARE_LIT))
		{
			self.impulse = BOT_AI_FOLLOW;
			return;
		}
		else
		{
			if ((self.ammo_nails > TF_FLARE_LIT))
			{
				self.impulse = BOT_MOVING;
				return;
			}
		}
	}
	if ((self.playerclass == BOT_AI_FOLLOW))
	{
		if ((self.target1 == world))
		{
			self.impulse = BOT_AI_BLAST;
			return;
		}
		targetdistance = vlen ((self.target1.origin - self.origin));
		if ((targetdistance < 92))
		{
			if ((self.ammo_shells > TF_FLARE_OFF))
			{
				self.impulse = BOT_AI_FOLLOW;
				return;
			}
		}
		if ((targetdistance > 600))
		{
			if (((self.ammo_shells > TF_FLARE_OFF) && (self.reload_shotgun < BOT_AI_BLAST)))
			{
				self.impulse = BOT_FIGHTING;
				return;
			}
		}
		if ((self.target1.health < 30))
		{
			if ((self.ammo_shells > TF_FLARE_OFF))
			{
				if ((targetdistance > 400))
				{
					self.impulse = BOT_FIGHTING;
				}
				else
				{
					self.impulse = BOT_AI_FOLLOW;
				}
				return;
			}
		}
		if ((self.ammo_rockets > TF_FLARE_LIT))
		{
			self.impulse = BOT_AI_BLAST;
			self.current_weapon = 8192;
			return;
		}
		if ((self.ammo_shells > TF_FLARE_OFF))
		{
			self.impulse = BOT_AI_FOLLOW;
			return;
		}
		if ((self.ammo_shells > TF_FLARE_LIT))
		{
			self.impulse = BOT_FIGHTING;
			return;
		}
	}
	if ((self.playerclass == BOT_MOVING))
	{
		if ((self.ammo_rockets > TF_FLARE_LIT))
		{
			self.impulse = BOT_AI_FLEE;
			return;
		}
		if ((self.ammo_shells > TF_FLARE_LIT))
		{
			self.impulse = BOT_FIGHTING;
			return;
		}
	}
	if ((self.playerclass == BOT_AI_GRAPPLE))
	{
		if ((((vlen ((self.origin - self.target1.origin)) < 64) && !(self.target1.tfstate & BOT_RESUPPLYING)) && (self.target1.playerclass != BOT_AI_GRAPPLE)))
		{
			if ((self.current_weapon != BOT_FIGHTING))
			{
				self.impulse = TF_FLARE_OFF;
			}
			return;
		}
		if ((self.ammo_nails > TF_FLARE_LIT))
		{
			self.impulse = BOT_AI_GRAPPLE;
			return;
		}
		if ((self.ammo_shells > TF_FLARE_LIT))
		{
			self.impulse = BOT_AI_FOLLOW;
			return;
		}
	}
	if ((self.playerclass == BOT_AI_FLEE))
	{
		if ((self.ammo_shells > TF_FLARE_LIT))
		{
			if ((self.target1.playerclass == BOT_FIGHTING))
			{
				self.impulse = BOT_AI_FOLLOW;
				return;
			}
			else
			{
				if ((self.ammo_cells > BOT_AI_FOLLOW))
				{
					self.impulse = BOT_AI_BLAST;
					return;
				}
				else
				{
					if ((self.ammo_shells > TF_FLARE_OFF))
					{
						self.impulse = BOT_AI_FOLLOW;
						return;
					}
					else
					{
						self.impulse = BOT_FIGHTING;
						return;
					}
				}
			}
		}
	}
	if ((self.playerclass == BOT_AI_BLAST))
	{
		if ((vlen ((self.origin - self.target1.origin)) > 275))
		{
			if ((self.ammo_rockets > TF_FLARE_LIT))
			{
				if ((self.current_weapon != 16384))
				{
					self.impulse = BOT_AI_BLAST;
				}
				return;
			}
			else
			{
				self.impulse = BOT_FIGHTING;
				return;
			}
		}
		if ((self.ammo_cells > TF_FLARE_LIT))
		{
			self.impulse = BOT_AI_FLEE;
			return;
		}
		if ((self.ammo_shells > TF_FLARE_LIT))
		{
			self.impulse = BOT_FIGHTING;
			return;
		}
	}
	if ((self.playerclass == BOT_DEFEND))
	{
		if ((vlen ((self.origin - self.target1.origin)) < 64))
		{
			self.impulse = TF_FLARE_OFF;
			return;
		}
		if (((self.ammo_shells > TF_FLARE_LIT) && !(self.target1.tfstate & 32768)))
		{
			self.impulse = BOT_FIGHTING;
			return;
		}
		if ((self.ammo_shells > BOT_AI_SCOUT))
		{
			self.impulse = BOT_AI_FOLLOW;
			return;
		}
		if ((self.ammo_nails > TF_FLARE_LIT))
		{
			self.impulse = BOT_MOVING;
			return;
		}
	}
	if ((self.playerclass == BOT_AI_FLAGRUN))
	{
		if ((((self.reload_super_shotgun < 14) && (self.ammo_shells > TF_FLARE_LIT)) && (vlen ((self.origin - self.target1.origin)) < 90)))
		{
			self.impulse = BOT_AI_FOLLOW;
			return;
		}
		if ((self.ammo_nails > TF_FLARE_LIT))
		{
			self.impulse = BOT_FIGHTING;
			return;
		}
	}
};

void () FindTargets =
{
	local entity possibleTarget;
	local vector vBotPointOfView;
	local vector vTargetBodyPart;

	if ((self.solid != BOT_AI_FOLLOW))
	{
		return;
	}
	if ((AllTargetsFull () != TF_FLARE_LIT))
	{
		return;
	}
	possibleTarget = find (world, classname, "player");
	while ((possibleTarget != world))
	{
		if ((possibleTarget.team_no != self.team_no))
		{
			if (((possibleTarget.origin_y > -600) && (possibleTarget.origin_y < 250)))
			{
				if ((possibleTarget.health > TF_FLARE_LIT))
				{
					traceline (self.origin, possibleTarget.origin, FALSE, world);
					if ((trace_fraction == TF_FLARE_OFF))
					{
						AddTarget (possibleTarget);
						return;
					}
					vBotPointOfView = self.origin;
					vBotPointOfView_z = (vBotPointOfView_z + BOT_RESUPPLYING);
					vTargetBodyPart = possibleTarget.origin;
					vTargetBodyPart_z = (vTargetBodyPart_z - BOT_RESUPPLYING);
					traceline (vBotPointOfView, vTargetBodyPart, FALSE, world);
					if ((trace_fraction == TF_FLARE_OFF))
					{
						AddTarget (possibleTarget);
						return;
					}
					vBotPointOfView = self.origin;
					vBotPointOfView_z = (vBotPointOfView_z + 20);
					vTargetBodyPart = possibleTarget.origin;
					vTargetBodyPart_z = (vTargetBodyPart_z + BOT_RESUPPLYING);
					traceline (vBotPointOfView, vTargetBodyPart, FALSE, world);
					if ((trace_fraction == TF_FLARE_OFF))
					{
						AddTarget (possibleTarget);
						return;
					}
				}
			}
		}
		possibleTarget = find (possibleTarget, classname, "player");
	}
	possibleTarget = find (world, classname, "building_sentrygun");
	while ((possibleTarget != world))
	{
		if ((possibleTarget.team_no != self.team_no))
		{
			traceline (self.origin, possibleTarget.origin, FALSE, world);
			if ((trace_fraction == TF_FLARE_OFF))
			{
				if ((possibleTarget.health > TF_FLARE_LIT))
				{
					AddTarget (possibleTarget);
					return;
				}
			}
		}
		possibleTarget = find (possibleTarget, classname, "building_sentrygun");
	}
};

void (vector aimAtThisPoint) AimHere =
{
	local vector directionToTarget;

	directionToTarget = vectoangles ((aimAtThisPoint - self.origin));
	if ((directionToTarget_x != TF_FLARE_LIT))
	{
		if ((directionToTarget_x > TF_FLARE_LIT))
		{
			if ((directionToTarget_x < 90))
			{
				directionToTarget_x = (TF_FLARE_LIT - directionToTarget_x);
			}
		}
		if ((directionToTarget_x > 270))
		{
			if ((directionToTarget_x < 360))
			{
				directionToTarget_x = fabs ((directionToTarget_x - 360));
			}
		}
	}
	self.v_angle_x = directionToTarget_x;
	self.v_angle_y = directionToTarget_y;
	self.v_angle_z = TF_FLARE_LIT;
};

void () InstantAim =
{
	AimHere (self.target1.origin);
	traceline (self.origin, self.target1.origin, FALSE, world);
	if ((trace_fraction == TF_FLARE_OFF))
	{
		self.button0 = TF_FLARE_OFF;
	}
	else
	{
		self.button0 = TF_FLARE_LIT;
	}
};

float (entity aTarget) GetCrosshairAngle =
{
	local vector directionToTarget;
	local float fTemp;
	local float enemyCrosshairAngle;

	directionToTarget = vectoangles ((self.origin - aTarget.origin));
	fTemp = aTarget.v_angle_y;
	if ((fTemp < TF_FLARE_LIT))
	{
		fTemp = (fTemp + 360);
	}
	enemyCrosshairAngle = (directionToTarget_y - fTemp);
	if ((enemyCrosshairAngle > 180))
	{
		enemyCrosshairAngle = (enemyCrosshairAngle - 360);
	}
	if ((enemyCrosshairAngle < -180))
	{
		enemyCrosshairAngle = (enemyCrosshairAngle + 360);
	}
	return (enemyCrosshairAngle);
};

void (float fDistance) LeadAim =
{
	local float fTime;
	local float fMissileSpeed;
	local vector vTarget;
	local vector vVelocity;

	if ((self.current_weapon & (FL_ONGROUND + FL_PARTIALGROUND)))
	{
		fMissileSpeed = 1000;
	}
	else
	{
		if ((self.current_weapon & (FL_WATERJUMP + 16384)))
		{
			fMissileSpeed = 600;
		}
		else
		{
			if ((self.current_weapon & (262144 + IT_INVISIBILITY)))
			{
				fMissileSpeed = 1500;
			}
			else
			{
				if ((self.current_weapon == 8192))
				{
					fMissileSpeed = 900;
				}
				else
				{
					InstantAim ();
					return;
				}
			}
		}
	}
	fTime = (fDistance / fMissileSpeed);
	if ((self.target1.flags & FL_ONGROUND))
	{
		fTime = (fTime * (0.4 + (random () * 0.4)));
		vTarget = (self.target1.origin + (self.target1.velocity * fTime));
	}
	else
	{
		fTime = (fTime * 0.9);
		vTarget = self.target1.origin;
		vVelocity = self.target1.velocity;
		vTarget = ((vTarget + (vVelocity * fTime)) + ((((0.5 * '0 0 -1') * sv_gravity) * fTime) * fTime));
	}
	if (((self.current_weapon & (8192 + 16384)) && (self.target1.flags & FL_ONGROUND)))
	{
		vTarget_z = (vTarget_z - 45);
		AimHere (vTarget);
		traceline (self.origin, (vTarget + '0 0 45'), FALSE, world);
		if ((trace_fraction == TF_FLARE_OFF))
		{
			self.button0 = TF_FLARE_OFF;
		}
		else
		{
			self.button0 = TF_FLARE_LIT;
		}
		return;
	}
	AimHere (vTarget);
	traceline (self.origin, vTarget, FALSE, world);
	if ((trace_fraction == TF_FLARE_OFF))
	{
		self.button0 = TF_FLARE_OFF;
	}
	else
	{
		self.button0 = TF_FLARE_LIT;
	}
};

void (float fDistance) DodgeEnemy =
{
	local float fEnemyAim;
	local float fDodgeAngle;

	fEnemyAim = GetCrosshairAngle (self.target1);
	if ((fDistance > 700))
	{
		fDistance = 700;
	}
	if ((fDistance > BOT_IMPULSE))
	{
		fDodgeAngle = (BOT_AI_SCOUT + ((700 - fDistance) * (20 / 700)));
	}
	else
	{
		fDodgeAngle = (30 + ((BOT_IMPULSE - fDistance) * (60 / BOT_IMPULSE)));
	}
	if (((fEnemyAim >= TF_FLARE_LIT) && (fEnemyAim < fDodgeAngle)))
	{
		StrafeRight ();
	}
	if (((fEnemyAim <= TF_FLARE_LIT) && (fEnemyAim >= (fDodgeAngle * CONTENT_EMPTY))))
	{
		StrafeLeft ();
	}
};

void () DodgeEnemyGrenades =
{
	local entity possibleGrenade;
	local vector DirToRun;

	possibleGrenade = findradius (self.origin, 225);
	while (possibleGrenade)
	{
		if ((possibleGrenade.classname == "grenade"))
		{
			if (((self.team_no != possibleGrenade.owner.team_no) || (possibleGrenade.owner == self)))
			{
				if ((possibleGrenade.touch == NailGrenadeTouch))
				{
					if ((self.flags & FL_ONGROUND))
					{
						self.button2 = TF_FLARE_OFF;
					}
					else
					{
						self.button2 = TF_FLARE_LIT;
					}
				}
				self.action = BOT_AVOIDING_HAZARD;
				self.keys = GetKeysByDir ((self.origin - possibleGrenade.origin));
				return;
			}
		}
		possibleGrenade = possibleGrenade.chain;
	}
	if ((self.action == BOT_AVOIDING_HAZARD))
	{
		self.keys = TF_FLARE_LIT;
		self.button1 = TF_FLARE_LIT;
		if ((self.target1 != world))
		{
			self.action = BOT_FIGHTING;
		}
		else
		{
			if ((self.waypoint1 != '0 0 0'))
			{
				self.action = BOT_MOVING;
			}
			else
			{
				self.action = BOT_IDLE;
			}
		}
	}
};

void () HandleGrens =
{
	local float fTime;
	local float fDistance;
	local float fExplodeTime;
	local entity eGren;
	local entity eTemp;
	local float fHeightDif;
	local float fGrenZVelocity;
	local float fArc;

	if (((self.tfstate & TF_FLARE_OFF) || (self.tfstate & FL_PARTIALGROUND)))
	{
		eGren = world;
		eTemp = find (world, classname, "GrenadeTimer");
		while (eTemp)
		{
			if (((eTemp.owner == self) && (eTemp != world)))
			{
				eGren = eTemp;
			}
			eTemp = find (eTemp, classname, "GrenadeTimer");
		}
		if ((eGren == world))
		{
			return;
		}
		fDistance = vlen ((self.target1.origin - self.origin));
		fTime = (fDistance / 600);
		if ((eGren.heat <= ((time + fTime) + 0.6)))
		{
			if ((eGren.heat <= ((time + fTime) + 0.4)))
			{
				if ((fDistance > 600))
				{
					self.button2 = TF_FLARE_OFF;
				}
				self.button0 = TF_FLARE_LIT;
			}
			else
			{
				if ((self.current_weapon & (16384 + FL_PARTIALGROUND)))
				{
					self.button0 = TF_FLARE_LIT;
				}
			}
		}
		if (((eGren.heat <= (time + fTime)) || (eGren.heat < (time + 0.4))))
		{
			if ((fDistance > 500))
			{
				if ((fDistance < 600))
				{
					self.v_angle_x = (self.v_angle_x - 20);
				}
				else
				{
					if ((fDistance < 100))
					{
						self.v_angle_x = (self.v_angle_x - 30);
					}
					else
					{
						self.v_angle_x = (self.v_angle_x - BOT_AI_SCOUT);
					}
				}
			}
			self.button0 = TF_FLARE_LIT;
			self.impulse = 152;
		}
	}
	else
	{
		if ((self.no_grenades_1 > TF_FLARE_LIT))
		{
			self.impulse = 150;
		}
	}
};

void () DitchGrens =
{
	if (((self.tfstate & TF_FLARE_OFF) || (self.tfstate & FL_PARTIALGROUND)))
	{
		self.impulse = 152;
	}
};

void () UseGren =
{
	local float fTime;
	local float fDistance;
	local float fExplodeTime;
	local entity eGren;
	local entity eTemp;
	local float fHeightDif;
	local float fGrenZVelocity;
	local float fArc;

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
		if ((eGren == world))
		{
			return;
		}
		fDistance = vlen ((self.target1.origin - self.origin));
		fTime = (fDistance / 600);
		if ((eGren.heat < 0.5))
		{
			fTime = TF_FLARE_LIT;
		}
		if ((eGren.heat <= ((time + fTime) + 0.6)))
		{
			if ((eGren.heat <= ((time + fTime) + 0.4)))
			{
				if ((fDistance > 600))
				{
					self.button2 = TF_FLARE_OFF;
				}
				self.button0 = TF_FLARE_LIT;
			}
			else
			{
				if ((self.current_weapon & (16384 + FL_PARTIALGROUND)))
				{
					self.button0 = TF_FLARE_LIT;
				}
			}
		}
		if ((eGren.heat <= (time + fTime)))
		{
			if ((fDistance < 100))
			{
				self.v_angle_x = (self.v_angle_x - 30);
			}
			if ((fDistance > 500))
			{
				if ((fDistance < 600))
				{
					self.v_angle_x = (self.v_angle_x - 20);
				}
				else
				{
					self.v_angle_x = (self.v_angle_x - BOT_AI_SCOUT);
				}
			}
			self.button0 = TF_FLARE_LIT;
			self.impulse = 152;
		}
	}
};

void () AttackVisible =
{
	local float fDistance;

	PickBestWeapon ();
	if ((self.current_weapon & (BOT_FIGHTING + BOT_RESUPPLYING)))
	{
		fDistance = vlen ((self.origin - self.target1.origin));
		LeadAim (fDistance);
		GotoLocation (self.target1.origin);
		DodgeEnemy ();
		self.button0 = TF_FLARE_OFF;
		UseGren ();
	}
	if ((self.current_weapon & (32768 + 4096)))
	{
		fDistance = vlen ((self.origin - self.target1.origin));
		LeadAim (fDistance);
		GotoLocation (self.target1.origin);
		DodgeEnemy ();
		UseGren ();
		return;
	}
	if ((self.current_weapon & ((IT_INVISIBILITY + 8192) + FL_WATERJUMP)))
	{
		fDistance = vlen ((self.origin - self.target1.origin));
		LeadAim (fDistance);
		if ((fDistance > 400))
		{
			self.keys = KEY_MOVEFORWARD;
		}
		else
		{
			if ((fDistance < BOT_IMPULSE))
			{
				self.keys = KEY_MOVEBACK;
			}
			else
			{
				if ((random () < 0.5))
				{
					self.keys = KEY_MOVEFORWARD;
				}
				else
				{
					self.keys = KEY_MOVEBACK;
				}
			}
		}
		DodgeEnemy ();
		if ((self.flags & FL_ONGROUND))
		{
			vlen (self.velocity);
			if ((vlen (self.velocity) > (0.8 * self.maxfbspeed)))
			{
				if ((random () < 0.05))
				{
					self.button2 = TF_FLARE_OFF;
				}
			}
			else
			{
				self.button2 = TF_FLARE_LIT;
			}
		}
		HandleGrens ();
		return;
	}
	else
	{
		fDistance = vlen ((self.origin - self.target1.origin));
		LeadAim (fDistance);
		GotoLocation (self.target1.origin);
		DodgeEnemy ();
		if ((fDistance > BOT_IMPULSE))
		{
			if ((self.flags & FL_ONGROUND))
			{
				vlen (self.velocity);
				if ((vlen (self.velocity) > (0.8 * self.maxfbspeed)))
				{
					if ((random () < 0.05))
					{
						self.button2 = TF_FLARE_OFF;
					}
				}
				else
				{
					self.button2 = TF_FLARE_LIT;
				}
			}
		}
		HandleGrens ();
		return;
	}
};

void () AttackTargets =
{
	local entity tempTarget;

	if ((self.target1 == world))
	{
		return;
	}
	if (((((self.target1.health <= TF_FLARE_LIT) || (self.target1.has_disconnected == TF_FLARE_OFF)) || ((self.target1.team_no == TF_FLARE_OFF) && (self.target1.origin_y < -700))) || ((self.target1.team_no == BOT_FIGHTING) && (self.target1.origin_y > 350))))
	{
		ClearTarget (TF_FLARE_OFF);
		return;
	}
	traceline (self.origin, self.target1.origin, FALSE, world);
	if ((trace_fraction == TF_FLARE_OFF))
	{
		self.target1.lastSighted = self.target1.origin;
		AttackVisible ();
		return;
	}
	if ((self.target2 != world))
	{
		traceline (self.origin, self.target2.origin, FALSE, world);
		if ((trace_fraction == TF_FLARE_OFF))
		{
			self.target2.lastSighted = self.target2.origin;
			tempTarget = self.target1;
			self.target1 = self.target2;
			self.target2 = tempTarget;
			AttackVisible ();
			return;
		}
	}
	if ((self.target3 != world))
	{
		traceline (self.origin, self.target3.origin, FALSE, world);
		if ((trace_fraction == TF_FLARE_OFF))
		{
			self.target3.lastSighted = self.target3.origin;
			tempTarget = self.target1;
			self.target1 = self.target3;
			self.target3 = tempTarget;
			AttackVisible ();
			return;
		}
	}
	self.button0 = TF_FLARE_LIT;
	if ((vlen ((self.target1.lastSighted - self.target1.origin)) > 500))
	{
		ClearTarget (TF_FLARE_OFF);
	}
	else
	{
		if ((vlen ((self.target1.lastSighted - self.origin)) > 20))
		{
			GotoLocation (self.target1.lastSighted);
		}
		else
		{
			if ((vlen ((self.origin - self.target1.origin)) > 500))
			{
				ClearTarget (TF_FLARE_OFF);
			}
			else
			{
				GotoLocation (self.target1.origin);
			}
		}
	}
	if (((((self.target2 != world) || (vlen ((self.target2.lastSighted - self.target2.origin)) > 500)) || (vlen ((self.origin - self.target2.origin)) > 500)) || (self.target2.health <= TF_FLARE_LIT)))
	{
		ClearTarget (BOT_FIGHTING);
	}
	if (((((self.target3 != world) || (vlen ((self.target3.lastSighted - self.target3.origin)) > 500)) || (vlen ((self.origin - self.target3.origin)) > 500)) || (self.target3.health <= TF_FLARE_LIT)))
	{
		ClearTarget (BOT_AI_FOLLOW);
	}
};
