
void (vector vTarget) HitWithSpanner =
{
	local vector lookhere;

	if ((vlen ((vTarget - self.origin)) < 45))
	{
		self.keys = TF_FLARE_LIT;
		lookhere = vectoangles ((vTarget - self.origin));
		lookhere_x = TF_FLARE_LIT;
		self.v_angle = lookhere;
		self.current_weapon = BOT_DEFEND;
		self.button0 = TF_FLARE_OFF;
	}
	else
	{
		MoveToLocation (vTarget);
	}
};
