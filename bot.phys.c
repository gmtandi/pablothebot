
float (float key) CL_KeyState =
{
	return (((self.keys & key) > TF_FLARE_LIT));
};

void () CL_KeyMove =
{
	local float anglespeed;
	local vector view;

	self.movevect = '0 0 0';
	self.movevect_y = (self.movevect_y + (350 * CL_KeyState (KEY_MOVERIGHT)));
	self.movevect_y = (self.movevect_y - (350 * CL_KeyState (KEY_MOVELEFT)));
	self.movevect_x = (self.movevect_x + (BOT_IMPULSE * CL_KeyState (KEY_MOVEFORWARD)));
	self.movevect_x = (self.movevect_x - (BOT_IMPULSE * CL_KeyState (KEY_MOVEBACK)));
	self.movevect_z = (self.movevect_z + (BOT_IMPULSE * CL_KeyState (KEY_MOVEUP)));
	self.movevect_z = (self.movevect_z - (BOT_IMPULSE * CL_KeyState (KEY_MOVEDOWN)));
	self.movevect = (self.movevect * BOT_FIGHTING);
	if (((self.current_weapon == 32768) && (self.button0 == TF_FLARE_OFF)))
	{
		self.movevect = '0 0 0';
		return;
	}
	if ((self.is_building == TF_FLARE_OFF))
	{
		self.movevect = '0 0 0';
		return;
	}
	if ((self.v_angle_x > 80))
	{
		self.v_angle_x = 80;
	}
	else
	{
		if ((self.v_angle_x < -70))
		{
			self.v_angle_x = -70;
		}
	}
	self.v_angle_z = TF_FLARE_LIT;
	self.v_angle_y = anglemod (self.v_angle_y);
};

void () SV_UserFriction =
{
	local vector vel;
	local vector start;
	local vector stop;
	local float sped;
	local float friction;
	local float newspeed;

	vel = self.velocity;
	vel_z = TF_FLARE_LIT;
	sped = vlen (vel);
	vel = self.velocity;
	if (!sped)
	{
		return;
	}
	stop_x = (self.origin_x + (vel_x / (sped * BOT_RESUPPLYING)));
	start_x = (self.origin_x + (vel_x / (sped * BOT_RESUPPLYING)));
	stop_y = (self.origin_y + (vel_y / (sped * BOT_RESUPPLYING)));
	start_y = (self.origin_y + (vel_y / (sped * BOT_RESUPPLYING)));
	start_z = (self.origin_z + self.mins_z);
	stop_z = (start_z - 34);
	traceline (start, stop, TRUE, self);
	if ((trace_fraction == TF_FLARE_OFF))
	{
		friction = (sv_friction * BOT_FIGHTING);
	}
	else
	{
		friction = sv_friction;
	}
	if ((sped < sv_stopspeed))
	{
		newspeed = (sped - ((frametime * sv_stopspeed) * friction));
	}
	else
	{
		newspeed = (sped - ((frametime * sped) * friction));
	}
	if ((newspeed < TF_FLARE_LIT))
	{
		newspeed = TF_FLARE_LIT;
	}
	newspeed = (newspeed / sped);
	self.velocity_y = (vel_y * newspeed);
	self.velocity_x = (vel_x * newspeed);
};

void () SV_WaterJump =
{
	if (((time > self.teleport_time) || !self.waterlevel))
	{
		self.flags = (self.flags - (self.flags & FL_WATERJUMP));
		self.teleport_time = TF_FLARE_LIT;
	}
	self.velocity_x = self.movedir_x;
	self.velocity_y = self.movedir_y;
};

void () DropPunchAngle =
{
	local float len;

	len = vlen (self.punchangle);
	self.punchangle = normalize (self.punchangle);
	len = (len - (BOT_AI_SCOUT * frametime));
	if ((len < TF_FLARE_LIT))
	{
		len = TF_FLARE_LIT;
	}
	self.punchangle = (self.punchangle * len);
};

void (vector wishvel) SV_AirAccelerate =
{
	local float addspeed;
	local float wishspd;
	local float accelspeed;
	local float currentspeed;

	wishspd = vlen (wishvel);
	wishvel = normalize (wishvel);
	if ((wishspd > 30))
	{
		wishspd = 30;
	}
	currentspeed = (self.velocity * wishvel);
	addspeed = (wishspd - currentspeed);
	if ((addspeed <= TF_FLARE_LIT))
	{
		return;
	}
	accelspeed = (((BOT_AI_SCOUT * sv_accelerate) * wishspd) * frametime);
	if ((accelspeed > addspeed))
	{
		accelspeed = addspeed;
	}
	self.velocity = (self.velocity + (accelspeed * wishvel));
};

void (vector wishvel) SV_Accelerate =
{
	local float addspeed;
	local float wishspd;
	local float accelspeed;
	local float currentspeed;

	wishspd = vlen (wishvel);
	wishvel = normalize (wishvel);
	currentspeed = (self.velocity * wishvel);
	addspeed = (wishspd - currentspeed);
	if ((addspeed <= TF_FLARE_LIT))
	{
		return;
	}
	accelspeed = ((sv_accelerate * wishspd) * frametime);
	if ((accelspeed > addspeed))
	{
		accelspeed = addspeed;
	}
	self.velocity = (self.velocity + (accelspeed * wishvel));
};

void () SV_WaterMove =
{
	local vector wishvel;
	local float wishspeed;
	local float addspeed;
	local float cspeed;
	local float newspeed;

	makevectors (self.v_angle);
	wishvel = ((v_right * self.movevect_y) + (v_forward * self.movevect_x));
	if ((self.movevect == '0 0 0'))
	{
		wishvel_z = (wishvel_z - 60);
	}
	else
	{
		wishvel_z = (wishvel_z + self.movevect_z);
	}
	wishspeed = vlen (wishvel);
	if ((wishspeed > sv_maxspeed))
	{
		wishvel = ((sv_maxspeed / wishspeed) * wishvel);
		wishspeed = sv_maxspeed;
	}
	wishspeed = (wishspeed * 0.7);
	cspeed = vlen (self.velocity);
	if (cspeed)
	{
		newspeed = (cspeed - ((frametime * cspeed) * sv_friction));
		if ((newspeed < TF_FLARE_LIT))
		{
			newspeed = TF_FLARE_LIT;
		}
		self.velocity = (self.velocity * (newspeed / cspeed));
	}
	else
	{
		newspeed = TF_FLARE_LIT;
	}
	if (!wishspeed)
	{
		return;
	}
	addspeed = (wishspeed - newspeed);
	if ((addspeed <= TF_FLARE_LIT))
	{
		return;
	}
	wishvel = normalize (wishvel);
	cspeed = ((sv_accelerate * wishspeed) * frametime);
	if ((cspeed > addspeed))
	{
		cspeed = addspeed;
	}
	self.velocity = (self.velocity + (cspeed * wishvel));
};

void () SV_AirMove =
{
	local vector wishvel;
	local vector vangle;

	vangle = self.v_angle;
	vangle_z = TF_FLARE_LIT;
	vangle_x = TF_FLARE_LIT;
	makevectors (vangle);
	if (((time < self.teleport_time) && (self.movevect_x < TF_FLARE_LIT)))
	{
		self.movevect_x = TF_FLARE_LIT;
	}
	wishvel = ((v_right * self.movevect_y) + (v_forward * self.movevect_x));
	if ((self.movetype != MOVETYPE_WALK))
	{
		wishvel_z = self.movevect_z;
	}
	else
	{
		wishvel_z = TF_FLARE_LIT;
	}
	if ((vlen (wishvel) > sv_maxspeed))
	{
		wishvel = (normalize (wishvel) * sv_maxspeed);
	}
	if ((self.movetype == MOVETYPE_NOCLIP))
	{
		self.velocity = wishvel;
	}
	else
	{
		if ((self.flags & FL_ONGROUND))
		{
			SV_UserFriction ();
			SV_Accelerate (wishvel);
		}
		else
		{
			SV_AirAccelerate (wishvel);
		}
	}
};

void () SV_ClientThink =
{
	local vector vangle;

	if ((self.movetype == MOVETYPE_NONE))
	{
		return;
	}
	DropPunchAngle ();
	if ((self.health <= TF_FLARE_LIT))
	{
		return;
	}
	self.v_angle_z = TF_FLARE_LIT;
	self.angles_z = (self.v_angle_z * BOT_MOVING);
	vangle = (self.v_angle + self.punchangle);
	if (!self.fixangle)
	{
		self.angles_x = (vangle_x / CONTENT_WATER);
		self.angles_y = vangle_y;
	}
	else
	{
		self.fixangle = TF_FLARE_LIT;
	}
	if ((self.flags & FL_WATERJUMP))
	{
		SV_WaterJump ();
		return;
	}
	if (((self.waterlevel >= BOT_FIGHTING) && (self.movetype != MOVETYPE_NOCLIP)))
	{
		SV_WaterMove ();
		return;
	}
	SV_AirMove ();
};

float () SV_RunThink =
{
	local float thinktime;
	local float bkuptime;

	thinktime = self.nextthink;
	bkuptime = time;
	if (((thinktime <= TF_FLARE_LIT) || (thinktime > (time + frametime))))
	{
		return (TRUE);
	}
	if ((thinktime < time))
	{
		thinktime = time;
	}
	self.nextthink = TF_FLARE_LIT;
	time = thinktime;
	other = world;
	makevectors (self.v_angle);
	self.think ();
	time = bkuptime;
	return (TRUE);
};

void (float scale) SV_AddGravity =
{
	if (!(self.flags & FL_ONGROUND))
	{
		self.velocity_z = (self.velocity_z - ((scale * sv_gravity) * frametime));
	}
};

float () SV_CheckWater =
{
	local vector point;
	local float cont;

	point_x = self.origin_x;
	point_y = self.origin_y;
	self.waterlevel = TF_FLARE_LIT;
	self.watertype = CONTENT_EMPTY;
	point_z = ((self.origin_z + self.mins_z) + TF_FLARE_OFF);
	cont = pointcontents (point);
	if ((cont <= CONTENT_WATER))
	{
		self.watertype = cont;
		self.waterlevel = TF_FLARE_OFF;
		point_z = (self.origin_z + ((self.mins_z + self.maxs_z) * 0.5));
		cont = pointcontents (point);
		if ((cont <= CONTENT_WATER))
		{
			self.waterlevel = BOT_FIGHTING;
			point_z = (self.origin_z + self.view_ofs_z);
			cont = pointcontents (point);
			if ((cont <= CONTENT_WATER))
			{
				self.waterlevel = BOT_AI_FOLLOW;
			}
		}
	}
	return ((self.waterlevel > TF_FLARE_OFF));
};

void () RemoveThud =
{
	local entity oself;

	if ((other == world))
	{
		if ((self.flags & FL_ONGROUND))
		{
			self.flags = (self.flags - FL_ONGROUND);
		}
	}
	else
	{
		if ((other == self.owner))
		{
			return;
		}
		if ((self.owner.solid == SOLID_NOT))
		{
			return;
		}
		oself = other;
		other = self.owner;
		self = oself;
		if ((self.solid == SOLID_BSP))
		{
			if (self.touch)
			{
				self.touch ();
			}
		}
		return;
	}
};

void () SV_CheckOnGround =
{
	local vector org;
	local float currentflags;

	org = self.origin;
	currentflags = self.flags;
	self.flags = ((self.flags | FL_ONGROUND) | FL_PARTIALGROUND);
	walkmove (TF_FLARE_LIT, TF_FLARE_LIT);
	self.flags = (currentflags | FL_ONGROUND);
	self.origin = org;
	traceline (org, (org + '0 0 50'), TRUE, self);
	if (((self.waterlevel == BOT_AI_FOLLOW) && (self.movetype == MOVETYPE_WALK)))
	{
		self.flags = (self.flags - FL_ONGROUND);
	}
	else
	{
		if (!droptofloor ())
		{
			self.flags = (self.flags - FL_ONGROUND);
		}
		else
		{
			if (((org_z - self.origin_z) < BOT_FIGHTING))
			{
				self.flags = (self.flags | FL_ONGROUND);
			}
			else
			{
				self.flags = (self.flags - FL_ONGROUND);
			}
		}
	}
	setorigin (self, org);
};

void (vector dir) botCheckForStep =
{
	local vector currentorigin;
	local float currentflags;
	local float yaw;
	local float stepdistance;
	local float movedistance;

	currentorigin = self.origin;
	currentflags = self.flags;
	self.flags = (FL_ONGROUND | FL_PARTIALGROUND);
	dir = normalize (dir);
	dir_z = TF_FLARE_LIT;
	yaw = vectoyaw (dir);
	if (walkmove (yaw, BOT_AI_FOLLOW))
	{
		if (droptofloor ())
		{
			stepdistance = (self.origin_z - currentorigin_z);
			movedistance = (self.origin_y - currentorigin_y);
			if ((((stepdistance > TF_FLARE_LIT) && (stepdistance <= BOT_RESUPPLYING)) && (movedistance != TF_FLARE_LIT)))
			{
				self.flags = (currentflags | FL_PARTIALGROUND);
				return;
			}
		}
	}
	self.flags = currentflags;
	setorigin (self, currentorigin);
};

void () PostPhysics =
{
	local vector obstr;
	local float back;
	local float dst;
	local float cflags;
	local string g;

	self = self.owner;
	self.velocity = ((self.velocity - self.phys_obj.dest1) + self.phys_obj.velocity);
	if ((self.phys_obj.dest2 == self.origin))
	{
		setorigin (self, self.phys_obj.origin);
		if ((self.movetype == MOVETYPE_WALK))
		{
			if ((self.phys_obj.dest1_x || self.phys_obj.dest1_y))
			{
				if (((self.flags & FL_ONGROUND) || (self.waterlevel >= BOT_FIGHTING)))
				{
					obstr = (self.phys_obj.movedir - self.origin);
					obstr_z = TF_FLARE_LIT;
					if ((vlen (obstr) > 0.1))
					{
						dst = vlen (obstr);
						back = vectoyaw (obstr);
						cflags = self.flags;
						self.flags = (self.flags | FL_PARTIALGROUND);
						if (walkmove (back, dst))
						{
							self.flags = cflags;
							self.phys_obj.dest1_z = TF_FLARE_LIT;
							self.velocity = ((self.velocity + self.phys_obj.dest1) - self.phys_obj.velocity);
							if ((self.obs_time > (time + 0.2)))
							{
								self.obs_time = (time + 0.2);
							}
						}
						else
						{
							if ((dst > BOT_FIGHTING))
							{
								frik_obstructed (obstr);
							}
							else
							{
								self.obs_time = TF_FLARE_LIT;
							}
						}
					}
				}
			}
		}
	}
	SV_CheckOnGround ();
	PlayerPostThink ();
	BotAI ();
	self.dmg_save = TF_FLARE_LIT;
	self.dmg_take = TF_FLARE_LIT;
};

void () SV_FlyMove =
{
	local vector r;

	if ((self.phys_obj == world))
	{
		error ("No physics entity spawned!\nMake sure BotInit was called\n");
		return;
	}
	setmodel (self.phys_obj, string_null);
	self.phys_obj.movetype = MOVETYPE_STEP;
	self.phys_obj.solid = SOLID_TRIGGER;
	self.phys_obj.touch = RemoveThud;
	self.mins = VEC_HULL_MIN;
	self.maxs = VEC_HULL_MAX;
	setsize (self.phys_obj, self.mins, self.maxs);
	self.phys_obj.origin = self.origin;
	self.phys_obj.dest2 = self.origin;
	self.phys_obj.watertype = TF_FLARE_LIT;
	self.phys_obj.movedir = (self.origin + (frametime * self.velocity));
	self.phys_obj.velocity = self.velocity;
	self.phys_obj.dest1 = self.velocity;
	self.phys_obj.velocity_z = (self.phys_obj.velocity_z + (sv_gravity * frametime));
	self.phys_obj.flags = TF_FLARE_LIT;
	self.phys_obj.think = PostPhysics;
	self.phys_obj.nextthink = time;
};

void () SV_Physics_Toss =
{
	if (!SV_RunThink ())
	{
		return;
	}
	if ((self.flags & FL_ONGROUND))
	{
		BotAI ();
		return;
	}
	if ((self.movetype != MOVETYPE_FLY))
	{
		SV_AddGravity (TF_FLARE_OFF);
	}
	self.angles = (self.angles + (frametime * self.avelocity));
	SV_FlyMove ();
};

void () SV_Physics_Client =
{
	PlayerPreThink ();
	if ((self.movetype == MOVETYPE_NONE))
	{
		if (!SV_RunThink ())
		{
			return;
		}
		PlayerPostThink ();
		BotAI ();
	}
	else
	{
		if (((self.movetype == MOVETYPE_WALK) || (self.movetype == MOVETYPE_STEP)))
		{
			if (!SV_RunThink ())
			{
				return;
			}
			if ((!SV_CheckWater () && !(self.flags & FL_WATERJUMP)))
			{
				SV_AddGravity (TF_FLARE_OFF);
			}
			SV_FlyMove ();
		}
		else
		{
			if (((self.movetype == MOVETYPE_TOSS) || (self.movetype == MOVETYPE_BOUNCE)))
			{
				SV_Physics_Toss ();
			}
			else
			{
				if ((self.movetype == MOVETYPE_FLY))
				{
					if (!SV_RunThink ())
					{
						return;
					}
					SV_FlyMove ();
				}
				else
				{
					if ((self.movetype == MOVETYPE_NOCLIP))
					{
						if (!SV_RunThink ())
						{
							return;
						}
						self.origin = (self.origin + (frametime * self.velocity));
						PlayerPostThink ();
						BotAI ();
					}
					else
					{
						error ("SV_Physics_Client: Bad Movetype (BOT)");
					}
				}
			}
		}
	}
};
