/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "forca.h"

bool_t
xdr_game (XDR *xdrs, game *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, (1 + ( 4 )) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->players_slots, 4,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->players_in_room))
				 return FALSE;

		} else {
		{
			register int *genp;

			for (i = 0, genp = objp->players_slots;
				i < 4; ++i) {
				IXDR_PUT_LONG(buf, *genp++);
			}
		}
		IXDR_PUT_LONG(buf, objp->players_in_room);
		}
		 if (!xdr_vector (xdrs, (char *)objp->current_word, 50,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->hidden_word, 50,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->tip, 100,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->can_go))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->turn))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, (1 + ( 4 )) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->players_slots, 4,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->players_in_room))
				 return FALSE;

		} else {
		{
			register int *genp;

			for (i = 0, genp = objp->players_slots;
				i < 4; ++i) {
				*genp++ = IXDR_GET_LONG(buf);
			}
		}
		objp->players_in_room = IXDR_GET_LONG(buf);
		}
		 if (!xdr_vector (xdrs, (char *)objp->current_word, 50,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->hidden_word, 50,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->tip, 100,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->can_go))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->turn))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_vector (xdrs, (char *)objp->players_slots, 4,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->players_in_room))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->current_word, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->hidden_word, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->tip, 100,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->can_go))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->turn))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_player (XDR *xdrs, player *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	return TRUE;
}
