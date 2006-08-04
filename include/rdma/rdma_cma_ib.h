/*
 * Copyright (c) 2006 Intel Corporation.  All rights reserved.
 *
 * This Software is licensed under one of the following licenses:
 *
 * 1) under the terms of the "Common Public License 1.0" a copy of which is
 *    available from the Open Source Initiative, see
 *    http://www.opensource.org/licenses/cpl.php.
 *
 * 2) under the terms of the "The BSD License" a copy of which is
 *    available from the Open Source Initiative, see
 *    http://www.opensource.org/licenses/bsd-license.php.
 *
 * 3) under the terms of the "GNU General Public License (GPL) Version 2" a
 *    copy of which is available from the Open Source Initiative, see
 *    http://www.opensource.org/licenses/gpl-license.php.
 *
 * Licensee has the right to choose one of the above licenses.
 *
 * Redistributions of source code must retain the above copyright
 * notice and one of the license notices.
 *
 * Redistributions in binary form must reproduce both the above copyright
 * notice, one of the license notices in the documentation
 * and/or other materials provided with the distribution.
 *
 */

#if !defined(RDMA_CMA_IB_H)
#define RDMA_CMA_IB_H

#include <rdma/rdma_cma.h>


/* IB specific option names for get/set. */
enum {
	IB_PATH_OPTIONS = 1,	/* struct ibv_kern_path_rec */
	IB_CM_REQ_OPTIONS = 2	/* struct ib_cm_req_opt */
};

struct ib_cm_req_opt {
	uint8_t		remote_cm_response_timeout;
	uint8_t		local_cm_response_timeout;
	uint8_t		max_cm_retries;
};

/**
 * rdma_get_dst_attr - Retrieve information about a UDP destination.
 * @id: Connection identifier associated with the request.
 * @addr: Address of remote destination to retrieve information about.
 * @ah_attr: Address handle attributes.  A caller uses these attributes to
 *   create an address handle when communicating with the destination.
 * @qpn: The remote QP number associated with the UDP address.
 * @qkey: The QKey of the remote QP.
 *
 * Users must have called rdma_connect() to resolve the destination information.
 */
int rdma_get_dst_attr(struct rdma_cm_id *id, struct sockaddr *addr,
		      struct ibv_ah_attr *ah_attr, uint32_t *remote_qpn,
		      uint32_t *remote_qkey);

#endif /* RDMA_CMA_IB_H */