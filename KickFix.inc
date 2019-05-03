/*
	KickFix by InDigitalEx
*/

#if defined _KickFix_included
	#endinput
#endif

#define _KickFix_included

#tryinclude <a_samp>

#if !defined _samp_included
	#error "Include <a_samp> before <KickFix>"
#endif

#if !defined KickFix_Delay
	#define KickFix_Delay		250
#endif

forward OnPlayerKick(playerid);

stock KickFix_Kick(playerid)
{
	if(!IsPlayerConnected(playerid))
		return false;

	OnPlayerKick(playerid);
	SetTimerEx("KickFix_KickTimer", KickFix_Delay, false, "i", playerid);
	return true;
}

forward KickFix_KickTimer(playerid);
public KickFix_KickTimer(playerid)
{
	return Kick(playerid);
}

#if defined _ALS_Kick
#undef Kick
#else
#define _ALS_Kick
#endif
#define Kick KickFix_Kick
