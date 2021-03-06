.. -*- rst -*-

===========================
 Ping instances (os-fping)
===========================

Pings instances and reports which instances are alive.

Ping Instances
==============

.. rest_method:: GET /v2.1/{tenant_id}/os-fping

Runs the fping utility to ping instances and reports which instances are alive.

Specify the ``all_tenants=1`` query parameter to ping instances for all tenants. For example:

::

  GET /os-fping?all_tenants=1

Specify the ``include`` and ``exclude`` query parameters to filter the results. For example:

::

  GET /os-fping?all_tenants=1&include=uuid1,uuid2&exclude=uuid3,uuid4

Policy defaults enable only users with the administrative role or the
owner of the server to perform this operation. Cloud providers can
change these permissions through the ``policy.json`` file.

Normal response codes: 200

Error response codes: serviceUnavailable(503), unauthorized(401), forbidden(403)

Request
-------

.. rest_parameters:: parameters.yaml

  - tenant_id: tenant_id
  - all_tenants: all_tenants
  - include: include
  - exclude: exclude

Response
--------

.. rest_parameters:: parameters.yaml

  - servers: servers
  - alive: alive
  - id: server_id
  - project_id: project_id

|

**Example Ping Instances**

.. literalinclude:: ../../doc/api_samples/os-fping/fping-get-resp.json
   :language: javascript

Ping An Instance
================

.. rest_method:: GET /v2.1/{tenant_id}/os-fping/{instance_id}

Runs the fping utility to ping an instance and reports whether the instance is alive.

Policy defaults enable only users with the administrative role or the
owner of the server to perform this operation. Cloud providers can
change these permissions through the ``policy.json`` file.

Normal response codes: 200

Error response codes: serviceUnavailable(503), unauthorized(401), forbidden(403),
itemNotFound(404)

Request
-------

.. rest_parameters:: parameters.yaml

  - tenant_id: tenant_id
  - instance_id: instance_id

Response
--------

.. rest_parameters:: parameters.yaml

  - server: server
  - alive: alive
  - id: server_id
  - project_id: project_id

|

**Example Ping An Instance**

.. literalinclude:: ../../doc/api_samples/os-fping/fping-get-details-resp.json
   :language: javascript
